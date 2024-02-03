#include "../../include/Action.h" 
#include <iostream>

PrintCustomerStatus::PrintCustomerStatus(int customerId) : customerId(customerId){};

PrintCustomerStatus *PrintCustomerStatus::clone() const{
    return new PrintCustomerStatus(*this);
};

void PrintCustomerStatus::act(WareHouse &wareHouse) {
    Customer *customer = &wareHouse.getCustomer(customerId);
    if(customer == &wareHouse.getDefaultCustomer()) // Handle a case customer not found 
    {
        error("Customer doesn't exist");
        std::cout << "Error: " + getErrorMsg() << endl;
    }
    else{
        std::cout << "CustomerID: " + to_string(customerId) << endl;
        vector<int> ordersIds = customer->getOrdersIds();
        for(int id:ordersIds){
            std::cout << "OrderId: " + to_string(id) << endl ;
            std::cout << "OrderStatus: " + wareHouse.getOrder(id).getStatusName() << endl;
        }
        std::cout << "numOrdersLeft: "<< customer->getOrdersLeft()  << std::endl;
        complete();
    }
    wareHouse.addAction(this);
};

string PrintCustomerStatus::toString() const {
    ActionStatus actionStatus = getStatus();
    if (actionStatus == ActionStatus::COMPLETED) {
        return "customerStatus " + std::to_string(customerId) + " COMPLETED";
    } else {
        return "customerStatus " + std::to_string(customerId) + " ERROR";
    }
};