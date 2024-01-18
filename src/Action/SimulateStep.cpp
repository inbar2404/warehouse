#include "../../include/Action.h" 
using namespace std;


SimulateStep::SimulateStep(int numOfSteps) : numOfSteps(numOfSteps) {};

void SimulateStep::act(WareHouse &wareHouse) {
    // TODO
};

string SimulateStep::toString() const {
    // TODO
};

SimulateStep* SimulateStep::clone() const {
    return new SimulateStep(*this);
};