#include "../../include/Volunteer.h"  
using namespace std;


DriverVolunteer::DriverVolunteer(int id, string name, int maxDistance, int distancePerStep)
    : Volunteer(id, name), maxDistance(maxDistance), distancePerStep(distancePerStep), distanceLeft(0) {};

DriverVolunteer* DriverVolunteer::clone() const {
    return new DriverVolunteer(*this);
};

int DriverVolunteer::getDistanceLeft() const {
    return distanceLeft;
};

int DriverVolunteer::getMaxDistance() const {
    return maxDistance;
};

int DriverVolunteer::getDistancePerStep() const {
    return distancePerStep;
}; 

bool DriverVolunteer::decreaseDistanceLeft() {
    distanceLeft -= distancePerStep;
    return distanceLeft <= 0;
};

bool DriverVolunteer::hasOrdersLeft() const {
    return true;
};

bool DriverVolunteer::canTakeOrder(const Order &order) const {
    return !isBusy();
};

void DriverVolunteer::acceptOrder(const Order &order) {
    activeOrderId = order.getId();
    distanceLeft = order.getDistance();
};

void DriverVolunteer::step() {
    // In case order is finished - update the completeOrderId parameter
    if (decreaseDistanceLeft()){
        completedOrderId = activeOrderId;
        activeOrderId = NO_ORDER;
    }
};

string DriverVolunteer::toString() const {
    string busyStatus = "False";
    if(isBusy()){
        busyStatus = "True";
    }
    if(activeOrderId == NO_ORDER){
        return "VolunteerID: " + std::to_string(getId()) + "\nisBusy: " + busyStatus + "\nOrderId: " 
    + "None" + "\ndistanceLeft: " + std::to_string(getDistanceLeft());
    }
    return "VolunteerID: " + std::to_string(getId()) + "\nisBusy: " + busyStatus + "\nOrderId: " 
    + std::to_string(activeOrderId) + "\ndistanceLeft: " + std::to_string(getDistanceLeft());
};