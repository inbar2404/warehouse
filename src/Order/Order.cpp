#include "../../include/Order.h" 
#include <ostream>


Order::Order(int id, int customerId, int distance) 
 : id(id), customerId(customerId), distance(distance), status(OrderStatus::PENDING), collectorId(NO_VOLUNTEER), driverId(NO_VOLUNTEER) {};

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

string Order::getStatusName() const
{
    string name = "";
    if(status == OrderStatus::PENDING){
        name = "Pending";
    }
    else if(status == OrderStatus::COLLECTING){
        name = "Collecting";
    }
    else if(status == OrderStatus::DELIVERING){
        name = "Delivering";
    }
    else if(status == OrderStatus::COMPLETED){
        name = "Completed";
    }
    return name;
};

const string Order::toString() const {
    string description = "";
    description += "OrderId: " + std::to_string(id);
    description += "\nOrderStatus: " + getStatusName(); 
    description += "\nCustomerID: " + std::to_string(customerId);
    if (collectorId==NO_VOLUNTEER){
        description += "\nCollector: None";
    }
    else{
        description += "\nCollector: " + std::to_string(collectorId);
    }
    if (driverId==NO_VOLUNTEER){
        description += "\nDriver: None";
    }
    else{
        description += "\nDriver: " + std::to_string(driverId);
    }
    return description;
};

Order* Order::clone() const {
    return new Order(*this);
};