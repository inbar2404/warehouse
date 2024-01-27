#include "../../include/Action.h" 

PrintCustomerStatus::PrintCustomerStatus(int customerId) : customerId(customerId){};

PrintCustomerStatus *PrintCustomerStatus::clone() const{
    return new PrintCustomerStatus(*this);
};

void PrintCustomerStatus::act(WareHouse &wareHouse) {

};

string PrintCustomerStatus::toString() const {

};