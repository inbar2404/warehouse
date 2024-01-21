#include "../../include/Customer.h"  

Customer::Customer(int id, const string &name, int locationDistance, int maxOrders)
 : id(id), name(name), locationDistance(locationDistance), maxOrders(maxOrders) {};

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
    return ordersId.size()
};

bool customer::canMakeOrder() const {
    if (this.maxOrders > this.ordersId.size()){
        return true;
    }
    return false;
};

const vector<int> &Customer :: getOrdersIds() const {
    return ordersId;
};

int customer::addOrder(int orderId) {
    if (){
        Order(orderId,this.id,this.locationDistance);
        return orderId;
    }
    return -1;
};

