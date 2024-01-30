#include "../../include/Action.h" 
#include <iostream>

PrintCustomerStatus::PrintCustomerStatus(int customerId) : customerId(customerId){};

PrintCustomerStatus *PrintCustomerStatus::clone() const{
    return new PrintCustomerStatus(*this);
};

void PrintCustomerStatus::act(WareHouse &wareHouse) {
    if(!wareHouse.isCustomerExist(customerId)){
        error("Customer doesn't exist");
        std::cout << "Error: " + getErrorMsg() << endl;
        this->setStatus(ActionStatus::ERROR);
    }
    else{
        std::cout << "CustomerID: " + to_string(customerId) << endl;
        Customer *C = &wareHouse.getCustomer(customerId);
        vector<int> ordersIds = C->getOrdersIds();
        for(int id:ordersIds){
            std::cout << "OrderID: " + to_string(id) << endl ;
            std::cout << "OrderStatus: " + wareHouse.getOrder(id).getStatusName() << endl;
        }
        std::cout << "numOrdersLeft: "<< C->getOrdersLeft()  << std::endl;
    }
    wareHouse.addAction(this);
    this->setStatus(ActionStatus::COMPLETED);
};

string PrintCustomerStatus::toString() const {
    ActionStatus actionStatus = getStatus();
    if (actionStatus == ActionStatus::COMPLETED) {
        return "customerStatus " + std::to_string(customerId) + " COMPLETED";
    } else {
        return "customerStatus " + std::to_string(customerId) + " ERROR";
    }
};