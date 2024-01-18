#include "../../include/Volunteer.h"  


// TODO: Make sure "ordersLeft" is implimented well
LimitedDriverVolunteer::LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep,int maxOrders)
    : DriverVolunteer(id, name, maxDistance, distancePerStep), maxOrders(maxOrders), ordersLeft(0) {}

LimitedDriverVolunteer* LimitedDriverVolunteer::clone() const {
    return new LimitedDriverVolunteer(*this);
}

int LimitedDriverVolunteer::getMaxOrders() const {
    return maxOrders;
}

int LimitedDriverVolunteer::getNumOrdersLeft() const {
    return ordersLeft;
}

bool LimitedDriverVolunteer::hasOrdersLeft() const {
    // TODO: Make sure thats what was requested
    return ordersLeft < maxOrders;
}

bool LimitedDriverVolunteer::canTakeOrder(const Order &order) const {
    // TODO: Find out what exactly they wanted in this question, then - update the line beneath
    return true;
}

void LimitedDriverVolunteer::acceptOrder(const Order &order) {
    // TODO: Prepare for new order(Reset activeOrderId,TimeLeft,DistanceLeft,OrdersLeft depends on the volunteer type)
}

string LimitedDriverVolunteer::toString() const {
    // TODO: Understand what type of discription do they want - then impliment
    return ""; // TODO: Remove this line according to the above comment
}