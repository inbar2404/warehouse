#include "../../include/Customer.h"  

Customer::Customer(int id, const string &name, int locationDistance, int maxOrders)
 : id(id), name(name), locationDistance(locationDistance), maxOrders(maxOrders) {};

const string &Customer::getName() const {
    return name;
};

int Customer::getId() const {
    return id;
};

int Customer::getCustomerDistance() const {
    return locationDistance;
};

int Customer::getMaxOrders() const {
    return maxOrders;
};

int Customer::getNumOrders() const {
    return ordersId.size();
};

bool Customer::canMakeOrder() const {
    if (maxOrders > ordersId.size()){
        return true;
    }
    return false;
};

const vector<int> &Customer :: getOrdersIds() const {
    return ordersId;
};


int Customer::addOrder(int orderId) {
    if (canMakeOrder()){
        ordersId.push_back(orderId);
        return orderId;
    }
    return -1;
};

int Customer::getOrdersLeft() const{
    return maxOrders - ordersId.size();
};