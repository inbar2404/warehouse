#include "../../include/Action.h" 

BackupWareHouse:: BackupWareHouse(){};

BackupWareHouse* BackupWareHouse::clone() const{
    return new BackupWareHouse(*this);
};

void BackupWareHouse::act(WareHouse &wareHouse) {

};

string BackupWareHouse::toString() const {

};