#include "../../include/Volunteer.h"  
using namespace std;


LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, string name, int coolDown ,int maxOrders)
    : CollectorVolunteer(id, name, coolDown), maxOrders(maxOrders), ordersLeft(maxOrders) {};

LimitedCollectorVolunteer* LimitedCollectorVolunteer::clone() const {
    return new LimitedCollectorVolunteer(*this);
};

bool LimitedCollectorVolunteer::hasOrdersLeft() const {
    return ordersLeft > 0;
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