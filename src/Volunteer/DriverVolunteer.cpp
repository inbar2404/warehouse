#include "../../include/Volunteer.h"  

// TODO: Make sure that init with o the distance left parameter is okay
DriverVolunteer::DriverVolunteer(int id, string name, int maxDistance, int distancePerStep)
    : Volunteer(id, name), maxDistance(maxDistance), distancePerStep(distancePerStep), distanceLeft(0) {}

DriverVolunteer* DriverVolunteer::clone() const {
    return new DriverVolunteer(*this);
}

int DriverVolunteer::getDistanceLeft() const {
    return distanceLeft;
}

int DriverVolunteer::getMaxDistance() const {
    return maxDistance;
}

int DriverVolunteer::getDistancePerStep() const {
    return distancePerStep;
}  

bool DriverVolunteer::decreaseDistanceLeft() {
    distanceLeft -= distancePerStep;
    return distanceLeft <= 0;
}

bool DriverVolunteer::hasOrdersLeft() const {
    return true;
}

bool DriverVolunteer::canTakeOrder(const Order &order) const {
    // TODO: In order to impliment the function I need to find out first how to know if the volunteer can take the order
    return true; // TODO: Remove this line according to the above comment
}

void DriverVolunteer::acceptOrder(const Order &order) {
    // TODO: Prepare for new order(Reset activeOrderId,TimeLeft,DistanceLeft,OrdersLeft depends on the volunteer type)
}

void DriverVolunteer::step() {
    // TODO: Impliment the function
}

string DriverVolunteer::toString() const {
    // TODO: Understand what type of discription do they want - then impliment
    return ""; // TODO: Remove this line according to the above comment
}
