#include "../../include/Volunteer.h"  


CollectorVolunteer::CollectorVolunteer(int id, string name, int coolDown)
    : Volunteer(id, name), coolDown(coolDown), timeLeft(0) {};

CollectorVolunteer* CollectorVolunteer::clone() const {
    return new CollectorVolunteer(*this);
};

void CollectorVolunteer::step() {
    // In case order is finished - update the completeOrderId parameter
    if (decreaseCoolDown())
    {
        completedOrderId = activeOrderId;
        activeOrderId = NO_ORDER;
    }
};

int CollectorVolunteer::getCoolDown() const {
    return coolDown;
};

int CollectorVolunteer::getTimeLeft() const {
    return timeLeft;
};

bool CollectorVolunteer::decreaseCoolDown() {
    if (timeLeft > 0) {
        timeLeft--;
    }
    return (timeLeft == 0);
};

bool CollectorVolunteer::hasOrdersLeft() const {
    return true;
};

bool CollectorVolunteer::canTakeOrder(const Order &order) const {
    return !isBusy();
};

void CollectorVolunteer::acceptOrder(const Order &order) {
    activeOrderId = order.getId();
    timeLeft = coolDown;
};

string CollectorVolunteer::toString() const {
    string busyStatus = "False";
    if(isBusy()){
        busyStatus = "True";
    }
    return "VolunteerID: " + std::to_string(getId()) + "\nisBusy: " + busyStatus + "\nOrderId: " 
    + std::to_string(activeOrderId) + "\ntimeLeft: " + std::to_string(getTimeLeft());
};