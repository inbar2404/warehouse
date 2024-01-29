#include "../../include/Action.h" 
#include <iostream>

// PrintVolunteerStatus::PrintVolunteerStatus(int id) : VolunteerId(id){};

// PrintVolunteerStatus *PrintVolunteerStatus::clone() const{
//     return new PrintVolunteerStatus(*this);
// };

// void PrintVolunteerStatus::act(WareHouse &wareHouse) {
//     if(!wareHouse.isVolunteerExist(VolunteerId)){
//         error("Volunteer doesn't exist");
//         std::cout << "Error: " + getErrorMsg() << endl;
//         this->setStatus(ActionStatus::ERROR);
//     }
//     else{
//         //ROTEM
//         //std::cout << "VolunteerId: " + to_string(VolunteerId) << endl;
//         // Volunteer V = WareHouse->getVolunteer(VolunteerId);
//         // std::cout << V.toString() << std::endl;
//     }
//     wareHouse.addAction(this);
//     this->setStatus(ActionStatus::COMPLETED);
// };

// string PrintVolunteerStatus::toString() const {
//     ActionStatus actionStatus = getStatus();
//     if (actionStatus == ActionStatus::COMPLETED) {
//         return "volunteerStatus " + std::to_string(VolunteerId) + " COMPLETED";
//     } else {
//         return "volunteerStatus " + std::to_string(VolunteerId) + " ERROR";
//     }
// };