#include "../../include/Action.h" 
#include <vector>
using namespace std;


SimulateStep::SimulateStep(int numOfSteps) : numOfSteps(numOfSteps) {};
    
void SimulateStep::act(WareHouse &wareHouse) {
    // TODO: Figure out if I can do that more efficiat + more important - make sure its work well
    // Execute step as the defined number of steps
    for (int currentStep = 0; currentStep < numOfSteps; ++currentStep) {
        // We first handle orders in process, then the pendings (otherwise peding will pass 2 steps at once) 
        vector<Order*> inProcessOrders = wareHouse.getFinishCollectOrders();
        for (Order* &order : inProcessOrders) 
        {
            DriverVolunteer driver = wareHouse.getAvailableDriver();
            driver.acceptOrder(*order);
            order->setDriverId(driver.getId());
            order->setStatus(OrderStatus::DELIVERING);
            // In order to move order between lists, the action is actually a combination of remove and then add again
            wareHouse.removeOrder(order);
            wareHouse.addOrder(order);
        } 
        
        vector<Order*> pendingOrders = wareHouse.getPendingOrders();
        for (Order* &order : pendingOrders)
        {
            CollectorVolunteer collector = wareHouse.getAvailableCollector();
            collector.acceptOrder(*order);
            order->setCollectorId(collector.getId()); 
            order->setStatus(OrderStatus::COLLECTING);
            // In order to move order between lists, the action is actually a combination of remove and then add again
            wareHouse.removeOrder(order);
            wareHouse.addOrder(order);
        }
        
        vector<Volunteer*> volunteersInAction = wareHouse.getvolunteersInAction();
        for (Volunteer* &volunteer : volunteersInAction)
        {
            volunteer->step();
            // In case a volunteer finish working on an order - move to new list
            if (volunteer->getActiveOrderId() == NO_ORDER)
            {
                Order order = wareHouse.getOrder(volunteer->getCompletedOrderId());
                // In order to move order between lists, the action is actually a combination of remove and then add again
                wareHouse.removeOrder(&order);
                wareHouse.addOrder(&order);
            }
        }

        // Delete volunteers that reach the max amount of orders
        wareHouse.removeLimitedVolunteersReachingMax();
    };
};

string SimulateStep::toString() const {
    return "SimulateStep: " + std::to_string(numOfSteps) + " steps";
};

SimulateStep* SimulateStep::clone() const {
    return new SimulateStep(*this);
};