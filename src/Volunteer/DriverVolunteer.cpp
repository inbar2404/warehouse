#include "../../include/Volunteer.h"  
using namespace std;

// TODO: Make sure that init with o the distance left parameter is okay
DriverVolunteer::DriverVolunteer(int id, string name, int maxDistance, int distancePerStep)
    : Volunteer(id, name), maxDistance(maxDistance), distancePerStep(distancePerStep), distanceLeft(0) {};

DriverVolunteer* DriverVolunteer::clone() const {
    return new DriverVolunteer(*this);
};

int DriverVolunteer::getDistanceLeft() const {
    return distanceLeft;
};

int DriverVolunteer::getMaxDistance() const {
    return maxDistance;
};

int DriverVolunteer::getDistancePerStep() const {
    return distancePerStep;
}; 

bool DriverVolunteer::decreaseDistanceLeft() {
    distanceLeft -= distancePerStep;
    return distanceLeft <= 0;
};

bool DriverVolunteer::hasOrdersLeft() const {
    return true;
};

bool DriverVolunteer::canTakeOrder(const Order &order) const {
    return activeOrderId == NO_ORDER;
};

void DriverVolunteer::acceptOrder(const Order &order) {
    activeOrderId = order.getId();
    distanceLeft = order.getDistance();
};

void DriverVolunteer::step() {
    // TODO: Impliment the function
};

string DriverVolunteer::toString() const {
    return "volunteer " + getName() + " driver " + to_string(maxDistance) + " " + to_string(distancePerStep);
};