#include "../../include/Action.h" 
#include <vector>
#include <typeinfo>
using namespace std;


SimulateStep::SimulateStep(int numOfSteps) : numOfSteps(numOfSteps) {};
    
void SimulateStep::act(WareHouse &wareHouse) {
    // Execute step as the defined number of steps
    for (int currentStep = 0; currentStep < numOfSteps; ++currentStep) {
        // TODO: check: Make sure there is no order starvation (more details in the assignment)
        // TODO: Check an example when the order matter and try to check if it work as expected
        // We first handle orders in process, then the pendings (otherwise peding will pass 2 steps at once) 
        vector<Order*> inProcessOrders = wareHouse.getFinishCollectOrders();
        for (Order* &order : inProcessOrders) 
        {
            // Look for an available driver
            bool hasFoundDriver = false;
            for(Volunteer* volunteer : wareHouse.getVolunteers()) {
                if (((typeid(*volunteer) == typeid(LimitedDriverVolunteer)) || 
                (typeid(*volunteer) == typeid(DriverVolunteer))) && 
                volunteer->canTakeOrder(*order)) 
                {
                    volunteer->acceptOrder(*order);
                    order->setDriverId(volunteer->getId());
                    order->setStatus(OrderStatus::DELIVERING);  
                    // In case order was in pending vector we should move it to inprocess vector
                    if(wareHouse.isOrderInPending(order))
                    {
                        // In order to move order between lists, the action is actually a combination of remove and then add again
                        wareHouse.removeFromList(order, "pending");
                        wareHouse.addOrder(order);
                    }
                    hasFoundDriver = true;
                    break;
                }
            }

            // In case order left without a driver -> bring back to pending list (if not already there)
            if((!wareHouse.isOrderInPending(order)) && !hasFoundDriver)
            {
                wareHouse.removeFromList(order, "inProcess");
                wareHouse.addOrder(order);
            }
        } 
        
        vector<Order*> pendingOrders = wareHouse.getPendingOrders();
        for (Order* &order : pendingOrders)
        {
            // Look for an available collector
            vector<Volunteer*> volunteersVector = wareHouse.getVolunteers();
            for(Volunteer* volunteer : volunteersVector) {
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
                wareHouse.removeFromList(order, "inProcess");
                // Update order status
                if(order->getStatus()==OrderStatus::DELIVERING)
                {
                    order->setStatus(OrderStatus::COMPLETED);
                }
                wareHouse.addOrder(order);
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