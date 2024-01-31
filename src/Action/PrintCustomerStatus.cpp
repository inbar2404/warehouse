#include "../../include/Action.h" 
#include <iostream>

PrintCustomerStatus::PrintCustomerStatus(int customerId) : customerId(customerId){};

PrintCustomerStatus *PrintCustomerStatus::clone() const{
    return new PrintCustomerStatus(*this);
};

void PrintCustomerStatus::act(WareHouse &wareHouse) {
    Customer *customer = &wareHouse.getCustomer(customerId);
    if(!(wareHouse.iscustomerExist(customerId))) // Handle a case customer not found 
    {
        error("Customer doesn't exist");
        std::cout << "Error: " + getErrorMsg() << endl;
        this->setStatus(ActionStatus::ERROR);
    }
    else{
        std::cout << "CustomerID: " + to_string(customerId) << endl;
        // ROTEM: You don't handle a case no ordersIds at all -> it get an exception, fix it
        vector<int> ordersIds = customer->getOrdersIds();
        for(int id:ordersIds){
            std::cout << "OrderId: " + to_string(id) << endl ;
            std::cout << "OrderStatus: " + wareHouse.getOrder(id).getStatusName() << endl;
        }
        std::cout << "numOrdersLeft: "<< customer->getOrdersLeft()  << std::endl;
        this->setStatus(ActionStatus::COMPLETED);
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