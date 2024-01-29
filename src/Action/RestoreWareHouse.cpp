#include "../../include/Action.h"
#include <iostream> 
extern WareHouse* backup;

// RestoreWareHouse:: RestoreWareHouse(){};

// RestoreWareHouse* RestoreWareHouse::clone() const{
//     return new RestoreWareHouse(*this);
// };

// void RestoreWareHouse::act(WareHouse &wareHouse) {
//     if(backup == nullptr)
//     {
//         error("No backup available");
//         std::cout << "Error: " + getErrorMsg() << endl;
//         this->setStatus(ActionStatus::ERROR);
//     }

//     else{
//         wareHouse = *backup;
//         this->setStatus(ActionStatus::COMPLETED);
//     }
// };

// string RestoreWareHouse::toString() const {
//     if(this->getStatus() == ActionStatus::COMPLETED)
//         return "Backup COMPLETED";
//     else return "Backup ERROR";
// };