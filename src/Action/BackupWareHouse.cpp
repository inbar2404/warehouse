#include "../../include/Action.h" 
extern WareHouse* backup;

// BackupWareHouse:: BackupWareHouse(){};

// BackupWareHouse* BackupWareHouse::clone() const{
//     return new BackupWareHouse(*this);
// };

// void BackupWareHouse::act(WareHouse &wareHouse) {
//     if(backup != nullptr)
//     {
//         delete backup;
//         backup = nullptr;
//     }
//     backup = new WareHouse(wareHouse);
//     wareHouse.addAction(this);
//     this->setStatus(ActionStatus::COMPLETED);
// };

// string BackupWareHouse::toString() const {
//     return "Backup COMPLETED";
// };