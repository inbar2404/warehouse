#include "../../include/Volunteer.h"  


CollectorVolunteer::CollectorVolunteer(int id, string name, int coolDown)
    : Volunteer(id, name), coolDown(coolDown), timeLeft(0) {};

CollectorVolunteer* CollectorVolunteer::clone() const {
    return new CollectorVolunteer(*this);
};

void step() {
    // TODO: Impliment the function
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
    // TODO: Make sure with someone that's what they mean - if not: change in all other volunteer classes
    return activeOrderId == NO_ORDER;
};

void CollectorVolunteer::acceptOrder(const Order &order) {
    activeOrderId = order.getId();
    timeLeft = 0; // TODO: Understand what is the correct value that new to be set + should I update another parameter?
};

string CollectorVolunteer::toString() const {
    return "volunteer " + getName() + " collector";
};