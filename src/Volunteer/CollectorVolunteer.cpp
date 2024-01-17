#include "../../include/Volunteer.h"  


CollectorVolunteer::CollectorVolunteer(int id, string name, int coolDown)
    : Volunteer(id, name), coolDown(coolDown), timeLeft(0) {}

CollectorVolunteer* CollectorVolunteer::clone() const {
    // TODO: Make sure my implimentation is okay
    return new CollectorVolunteer(*this);
}

void step() {
    // TODO: Impliment the function
}

int CollectorVolunteer::getCoolDown() const {
    return coolDown;
}

int CollectorVolunteer::getTimeLeft() const {
    return timeLeft;
}

bool CollectorVolunteer::decreaseCoolDown() {
    if (timeLeft > 0) {
        timeLeft--;
    }
    return (timeLeft == 0);
}

bool CollectorVolunteer::hasOrdersLeft() const {
    return true;
}

bool CollectorVolunteer::canTakeOrder(const Order &order) const {
    // TODO: In order to impliment the function I need to find out first how to know if the volunteer can take the order
    return true; // TODO: Remove this line according to the above comment
}

void CollectorVolunteer::acceptOrder(const Order &order) {
    // TODO: Prepare for new order(Reset activeOrderId,TimeLeft,DistanceLeft,OrdersLeft depends on the volunteer type)
}

string CollectorVolunteer::toString() const {
    // TODO: Understand what type of discription do they want - then impliment
    return ""; // TODO: Remove this line according to the above comment
}
