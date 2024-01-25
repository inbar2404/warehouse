#include "../../include/Action.h" 
#include <vector>
using namespace std;


SimulateStep::SimulateStep(int numOfSteps) : numOfSteps(numOfSteps) {};
    
void SimulateStep::act(WareHouse &wareHouse) {
    // TODO: Figure out if I can do that more efficiat
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
            // TODO: Move orders' inProcess list (wareHouse parameter) - make sure that's correct
        } 
        
        vector<Order*> pendingOrders = wareHouse.getPendingOrders();
        for (Order* &order : pendingOrders)
        {
            CollectorVolunteer collector = wareHouse.getAvailableCollector();
            collector.acceptOrder(*order);
            order->setCollectorId(collector.getId()); 
            order->setStatus(OrderStatus::COLLECTING);
            // TODO: Move orders' inProcess list (wareHouse parameter)
        }
        
        vector<Volunteer*> volunteersInAction = wareHouse.getvolunteersInAction();
        for (Volunteer* &volunteer : volunteersInAction)
        {
            volunteer->step();
            // TODO: If volunteer finish his process -> move to complete (also for collector? understand and update first comment)
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