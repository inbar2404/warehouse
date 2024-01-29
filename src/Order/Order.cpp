#include "../../include/Order.h" 
#include <ostream>


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

// string Order::StatusStr() const
// {
//     string StrStatus = "";
//     if(status == OrderStatus::PENDING){
//         StrStatus = "Pending";
//     }
//     else if(status == OrderStatus::COLLECTING){
//         StrStatus = "Collecting";
//     }
//     else if(status == OrderStatus::DELIVERING){
//         StrStatus = "Delivering";
//     }
//     else if(status == OrderStatus::COMPLETED){
//         StrStatus = "Completed";
//     }
//     return StrStatus;
// };

// const string Order::toString() const {
//     string Status = StatusStr();
//     string collectorIdStr = std::to_string(collectorId);
//     string driverIdStr = std::to_string(driverId);
//     if (collectorId==NO_VOLUNTEER){
//         collectorIdStr = "None";
//     }
//     if (driverId==NO_VOLUNTEER){
//         driverIdStr = "None";
//     }
//     // std::stringstream OrderStr;
//     // OrderStr << "OrderId: " << id << std::endl;
//     // OrderStr << "OrderStatus: " << Status << std::endl;
//     // OrderStr << "CustomerID: " << customerId << std::endl;
//     // OrderStr << "Collector: " << collectorIdStr << std::endl;
//     // OrderStr << "Driver: " << driverIdStr ;
//     // return OrderStr.str();
// };

Order* Order::clone() const {
    return new Order(*this);
};