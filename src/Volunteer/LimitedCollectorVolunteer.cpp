#include "../../include/Volunteer.h"  
using namespace std;

// TODO: Make sure "ordersLeft" is implimented well
LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, string name, int coolDown ,int maxOrders)
    : CollectorVolunteer(id, name, coolDown), maxOrders(maxOrders), ordersLeft(0) {};

LimitedCollectorVolunteer* LimitedCollectorVolunteer::clone() const {
    // TODO: Make sure my implimentation is okay
    return new LimitedCollectorVolunteer(*this);
};

bool LimitedCollectorVolunteer::hasOrdersLeft() const {
    // TODO: Make sure thats what was requested
    return ordersLeft < maxOrders;
};

bool LimitedCollectorVolunteer::canTakeOrder(const Order &order) const {
    // TODO: Find out what exactly they wanted in this question, then - update the line beneath
    return true;
};

void LimitedCollectorVolunteer::acceptOrder(const Order &order) {
    // Call the base class method in order to reset shared parameters
    CollectorVolunteer::acceptOrder(order);
    // Remove by one the amount of orders that the current volunteer can take
    ordersLeft -= 1;
};

int LimitedCollectorVolunteer::getMaxOrders() const {
    return maxOrders;
};

int LimitedCollectorVolunteer::getNumOrdersLeft() const {
    return ordersLeft;
};

string LimitedCollectorVolunteer::toString() const {
    // Using the string from the base class
    string baseString = CollectorVolunteer::toString();
    return baseString + " " + to_string(maxOrders);
};