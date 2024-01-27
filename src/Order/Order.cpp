#include "../../include/Order.h" 


Order::Order(int id, int customerId, int distance) 
 : id(id), customerId(customerId), distance(distance) {};

int Order::getId() const{
    return id;
};

int Order::getCustomerId() const{
    return customerId;
};

int Order::getDistance() const{
    return distance;
};

void Order::setStatus(OrderStatus _status){
    status = _status;
};

void Order::setCollectorId(int _collectorId){
    collectorId = _collectorId;
};

void Order::setDriverId(int _driverId){
    driverId = _driverId;
};

int Order::getCollectorId() const {
    return collectorId;
};

int Order::getDriverId() const {
    return driverId;
};

OrderStatus Order::getStatus() const {
    return status;
};

// ROTEM
const string Order::toString() const {
    return "";
};

Order* Order::clone() const {
    return new Order(*this);
};