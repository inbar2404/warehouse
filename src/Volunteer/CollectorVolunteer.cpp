#include "../../include/Volunteer.h"  


// TODO: Make sure with someone that my timeLeft init was their meaning - or 0?
CollectorVolunteer::CollectorVolunteer(int id, string name, int coolDown)
    : Volunteer(id, name), coolDown(coolDown), timeLeft(coolDown) {};

CollectorVolunteer* CollectorVolunteer::clone() const {
    return new CollectorVolunteer(*this);
};

void CollectorVolunteer::step() {
    decreaseCoolDown();
    // In case order is finished - update the completeOrderId parameter
    if (timeLeft == 0){
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

// TODO: Find out - shouldn't it be decreaseTimeLeft
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
    // TODO: Make sure with someone that's what they mean - if not: change in all other volunteer classes
    return activeOrderId == NO_ORDER;
};

void CollectorVolunteer::acceptOrder(const Order &order) {
    activeOrderId = order.getId();
    timeLeft = coolDown; // TODO: Make sure with someone that's was what they ment
};

string CollectorVolunteer::toString() const {
    return "volunteer " + getName() + " collector";
};