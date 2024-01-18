#include "../../include/Volunteer.h"  


// TODO: Make sure "ordersLeft" is implimented well
LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, string name, int coolDown ,int maxOrders)
    : CollectorVolunteer(id, name, coolDown), maxOrders(maxOrders), ordersLeft(0) {}

LimitedCollectorVolunteer* LimitedCollectorVolunteer::clone() const {
    // TODO: Make sure my implimentation is okay
    return new LimitedCollectorVolunteer(*this);
}

bool LimitedCollectorVolunteer::hasOrdersLeft() const {
    // TODO: Make sure thats what was requested
    return ordersLeft < maxOrders;
}

bool LimitedCollectorVolunteer::canTakeOrder(const Order &order) const {
    // TODO: Find out what exactly they wanted in this question, then - update the line beneath
    return true;
}

void LimitedCollectorVolunteer::acceptOrder(const Order &order) {
    // TODO: Prepare for new order(Reset activeOrderId,TimeLeft,DistanceLeft,OrdersLeft depends on the volunteer type)   
}

int LimitedCollectorVolunteer::getMaxOrders() const {
    return maxOrders;
}

int LimitedCollectorVolunteer::getNumOrdersLeft() const {
    return ordersLeft;
}

string LimitedCollectorVolunteer::toString() const {
    // TODO: Understand what type of discription do they want - then impliment
    return ""; // TODO: Remove this line according to the above comment
}
