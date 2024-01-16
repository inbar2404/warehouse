#include "../../include/Volunteer.h"  


CollectorVolunteer::CollectorVolunteer(int id, string name, int coolDown)
    : Volunteer(id, name), coolDown(coolDown), timeLeft(0) {}

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

// TODO: Impliment the next functions: clone, step, hasOrdersLeft, canTakeOrder, acceptOrder, ToString