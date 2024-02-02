#include "../../include/Action.h" 
#include <iostream>

PrintVolunteerStatus::PrintVolunteerStatus(int id) : volunteerId(id){};

PrintVolunteerStatus *PrintVolunteerStatus::clone() const{
    return new PrintVolunteerStatus(*this);
};


void PrintVolunteerStatus::act(WareHouse &wareHouse) {
    Volunteer *volunteer = &wareHouse.getVolunteer(volunteerId);
    if(volunteer == &wareHouse.getDefaultVolunteer()) // Handle a case voluteer was not found
    {
        error("Volunteer doesn't exist");
        std::cout << "Error: " + getErrorMsg() << endl;
    }
    else
    {
        string volunteerDescription = volunteer->toString();
        // In case "toString" method did not mentioned "ordersLeft" parameter, note it has no limit
        if (volunteerDescription.find("ordersLeft") == std::string::npos) 
        {
            volunteerDescription += "\nordersLeft: No Limit";
        } 
        std::cout << volunteerDescription << std::endl;
        this->setStatus(ActionStatus::COMPLETED);
    }
    wareHouse.addAction(this);
};

string PrintVolunteerStatus::toString() const {
    ActionStatus actionStatus = getStatus();
    if (actionStatus == ActionStatus::COMPLETED) {
        return "volunteerStatus " + std::to_string(volunteerId) + " COMPLETED";
    } else {
        return "volunteerStatus " + std::to_string(volunteerId) + " ERROR";
    }
};