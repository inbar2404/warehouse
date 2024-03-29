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
    return hasOrdersLeft() && DriverVolunteer::canTakeOrder(order);
};

void LimitedDriverVolunteer::acceptOrder(const Order &order) {
    // Call the base class method in order to reset shared parameters
    DriverVolunteer::acceptOrder(order);
    // Remove by one the amount of orders that the current volunteer can take
    ordersLeft -= 1;
};

string LimitedDriverVolunteer::toString() const {
    return DriverVolunteer::toString() + "\nordersLeft: " + to_string(ordersLeft);
};