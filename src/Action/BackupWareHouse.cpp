#include "../../include/Action.h" 

BackupWareHouse::BackupWareHouse(string customerName, string customerType, int distance, int maxOrders)
    : BaseAction() {};

BackupWareHouse *clone() const {
// override(?)
    return new BackupWareHouse(*this);
};

void BackupWareHouse::act(WareHouse &wareHouse) override () {

};

string BackupWareHouse::toString() const override () {

};