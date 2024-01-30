#include "../../include/Action.h" 
#include <iostream>


PrintOrderStatus::PrintOrderStatus(int id) : orderId(id){};

PrintOrderStatus *PrintOrderStatus::clone() const{
    return new PrintOrderStatus(*this);
};

void PrintOrderStatus::act(WareHouse &wareHouse) {
    Order *order = &wareHouse.getOrder(orderId);
    if(order == wareHouse.defaultOrder) // Handle a case order not found
    {
        error("Order doesn't exist");
        std::cout << "Error: " + getErrorMsg() << endl;
        this->setStatus(ActionStatus::ERROR);
    }
    else
    {
        cout << order->toString() << endl;
        wareHouse.addAction(this);
        this->setStatus(ActionStatus::COMPLETED);
    }
};

string PrintOrderStatus::toString() const {
    ActionStatus actionStatus = getStatus();
    if (actionStatus == ActionStatus::COMPLETED) {
        return "orderStatus " + std::to_string(orderId) + " COMPLETED";
    } else {
        return "orderStatus " + std::to_string(orderId) + " ERROR";
    }
};