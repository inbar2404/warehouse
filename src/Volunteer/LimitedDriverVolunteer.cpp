#include "../../include/Volunteer.h"  
using namespace std;


LimitedDriverVolunteer::LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep,int maxOrders)
    : DriverVolunteer(id, name, maxDistance, distancePerStep), maxOrders(maxOrders), ordersLeft(maxOrders) {};

LimitedDriverVolunteer* LimitedDriverVolunteer::clone() const {
    return new LimitedDriverVolunteer(*this);
};

int LimitedDriverVolunteer::getMaxOrders() const {
    return maxOrders;
};

int LimitedDriverVolunteer::getNumOrdersLeft() const {
    return ordersLeft;
};

bool LimitedDriverVolunteer::hasOrdersLeft() const {
    return ordersLeft > 0;
};

bool LimitedDriverVolunteer::canTakeOrder(const Order &order) const {
    // TODO: Find out what exactly they wanted in this question, then - update the line beneath
    return true;
};

void LimitedDriverVolunteer::acceptOrder(const Order &order) {
    // Call the base class method in order to reset shared parameters
    DriverVolunteer::acceptOrder(order);
    // Remove by one the amount of orders that the current volunteer can take
    ordersLeft -= 1;
};

string LimitedDriverVolunteer::toString() const {
    // Using the string from the base class
    string baseString = DriverVolunteer::toString();
    return baseString + " " + to_string(maxOrders);
};