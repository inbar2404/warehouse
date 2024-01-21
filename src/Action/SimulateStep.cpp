#include "../../include/Action.h" 
#include <vector>
using namespace std;


SimulateStep::SimulateStep(int numOfSteps) : numOfSteps(numOfSteps) {};
    
// TODO: Make sure funtion as excpected
void SimulateStep::act(WareHouse &wareHouse) {
    // We first handle orders in process, then the pendings (otherwise peding will pass 2 steps at once) 
    vector<Order*> inProcessOrders = wareHouse.getFinishCollectOrders();
    for (auto &order : inProcessOrders)
    {
        order->setDriverId(0); // TODO: Update with correct driverID
        order->setStatus(OrderStatus::DELIVERING);
    } 
    
    vector<Order*> pendingOrders = wareHouse.getPendingOrders();
    for (auto &order : pendingOrders)
    {
        order->setCollectorId(0); // TODO: Update with correct collectorID
        order->setStatus(OrderStatus::COLLECTING);
        // TODO: Move orders' inProcess list (wareHouse parameter) - Make sure for driver nothing need to be changed
    }
    
    vector<Volunteer*> volunteersInAction = wareHouse.getvolunteersInAction();
    for (auto &volunteer : volunteersInAction)
    {
        volunteer->step();
        // TODO: If volunteer finish his process -> move to complete (also for collector? understand and update first comment)
    }
    wareHouse.removeLimitedVolunteersReachingMax();
};

// TODO: Make sure that what was requested
string SimulateStep::toString() const {
    return "Preform a step in the simulator";
};

SimulateStep* SimulateStep::clone() const {
    return new SimulateStep(*this);
};