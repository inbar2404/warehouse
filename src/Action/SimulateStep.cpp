#include "../../include/Action.h" 
#include <vector>
#include <typeinfo>
using namespace std;


SimulateStep::SimulateStep(int numOfSteps) : numOfSteps(numOfSteps) {};
    
void SimulateStep::act(WareHouse &wareHouse) {
    // Execute step as the defined number of steps
    for (int currentStep = 0; currentStep < numOfSteps; ++currentStep) {
        // TODO: Make sure there is no order starvation (more details in the assignment)
        // TODO: Check an example when the order matter and try to check if it work as expected
        // We first handle orders in process, then the pendings (otherwise peding will pass 2 steps at once) 
        vector<Order*> inProcessOrders = wareHouse.getFinishCollectOrders();
        for (Order* &order : inProcessOrders) 
        {
            // Look for an available driver
            for(Volunteer* volunteer : wareHouse.getVolunteers()) {
                if (((typeid(*volunteer) == typeid(LimitedDriverVolunteer)) || 
                (typeid(*volunteer) == typeid(DriverVolunteer))) && 
                volunteer->canTakeOrder(*order)) 
                {
                    volunteer->acceptOrder(*order);
                    order->setDriverId(volunteer->getId());
                    // TODO: Check: Is it work in a case no driver is free? Should I return him to pending in this state?
                    order->setStatus(OrderStatus::DELIVERING);  
                    break;
                }
            }
        } 
        
        vector<Order*> pendingOrders = wareHouse.getPendingOrders();
        for (Order* &order : pendingOrders)
        {
            // Look for an available collector
            for(Volunteer* volunteer : wareHouse.getVolunteers()) {
                if (((typeid(*volunteer) == typeid(LimitedCollectorVolunteer)) || 
                (typeid(*volunteer) == typeid(CollectorVolunteer))) && 
                volunteer->canTakeOrder(*order)) 
                {
                    volunteer->acceptOrder(*order);
                    order->setCollectorId(volunteer->getId());
                    order->setStatus(OrderStatus::COLLECTING);
                    // In order to move order between lists, the action is actually a combination of remove and then add again
                    wareHouse.removeFromList(order, "pending");
                    wareHouse.addOrder(order);
                    break;
                }
            }
        }
        
        vector<Volunteer*> volunteersInAction;
        for (Volunteer* volunteer : wareHouse.getVolunteers())
        {
            if (volunteer->isBusy()){
                volunteersInAction.push_back(volunteer);
            }
        }

        for (Volunteer* &volunteer : volunteersInAction)
        {
            volunteer->step();
            // In case a volunteer finish working on an order - move to new list
            if (volunteer->getActiveOrderId() == NO_ORDER)
            {
                Order* order = wareHouse.getOrderPointer(volunteer->getCompletedOrderId());
                // In order to move order between lists, the action is actually a combination of remove and then add again
                wareHouse.removeFromList(order, "inProcess");
                wareHouse.addOrder(order);
                // Update order status
                if(order->getStatus()==OrderStatus::DELIVERING)
                {
                    order->setStatus(OrderStatus::COMPLETED);
                }
            }
        }

        // Delete volunteers that reach the max amount of orders
        wareHouse.removeLimitedVolunteersReachingMax();
    };
    wareHouse.addAction(this);
};

string SimulateStep::toString() const {
    return "simulateStep " + std::to_string(numOfSteps) + " COMPLETED";
};

SimulateStep* SimulateStep::clone() const {
    return new SimulateStep(*this);
};