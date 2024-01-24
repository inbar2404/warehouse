#include "../../include/Action.h" 

PrintCustomerStatus::PrintCustomerStatus(string customerName, string customerType, int distance, int maxOrders)
    : BaseAction() {};

PrintCustomerStatus *clone() const {
// override(?)
    return new PrintCustomerStatus(*this);
};

void PrintCustomerStatus::act(WareHouse &wareHouse) override () {

};

string PrintCustomerStatus::toString() const override () {

};