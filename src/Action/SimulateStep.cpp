#include "../../include/Action.h" 
#include <vector>
using namespace std;


SimulateStep::SimulateStep(int numOfSteps) : numOfSteps(numOfSteps) {};

void SimulateStep::act(WareHouse &wareHouse) {
    // TODO: Make sure funtion as excpected
    // We first handle orders in process, then the pendings (otherwise peding will pass 2 steps at once) 
    // TODO: For each order add driverID & orderStatus (Also while driving is inProcess)
    vector<Order*> inProcessOrders = wareHouse.getFinishCollectOrders();
    // TODO: For each order add collecterID & orderStatus and move to inProcess 
    vector<Order*> pendingOrders = wareHouse.getPendingOrders();
    vector<Volunteer*> volunteersInAction = wareHouse.getvolunteersInAction();
    // TODO: For each volunteer in action -> make a step (rather is a collector or driver)
    // TODO: If volunteer finish his process -> move to complete (also for collector? understand and update first comment)
    wareHouse.removeLimitedVolunteersReachingMax();
};

// TODO: Make sure that what was requested
string SimulateStep::toString() const {
    return "Preform a step in the simulator";
};

SimulateStep* SimulateStep::clone() const {
    return new SimulateStep(*this);
};