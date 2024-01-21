#include "../../include/Customer.h"  

Customer::Customer(int id, const string &name, int locationDistance, int maxOrders) : id(id), name(name), locationDistance(locationDistance), maxOrders(maxOrders) {};

const string &Customer::getName() const {
    return name;
};

int Customer::getId() const {
    return id;
};

int customer::getCustomerDistance() const {
    return locationDistance;
};

int customer::getMaxOrders() const {
    return maxOrders;
}

int customer::getNumOrders() const {

};

bool customer::canMakeOrder() const {
    if (maxOrders > ){
        return true;
    }
    return false;
};

const vector<int> &Customer :: getOrdersIds() const {

};

int customer::addOrder(int orderId) {

};

