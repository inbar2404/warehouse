#include "../../include/Action.h" 
#include <iostream>

AddOrder::AddOrder(int id):
customerId(id){};

AddOrder* AddOrder::clone() const {
    return new AddOrder(*this);
};

void AddOrder::act(WareHouse &wareHouse) {
    Customer *customer = &wareHouse.getCustomer(customerId);
    if (customer==&wareHouse.getDefaultCustomer() || !customer->canMakeOrder()) //  Handle a case customer was not found 
    {
        error("Cannot place this order");
        std::cout << "Error: " + getErrorMsg() << endl;
    }
    else
    {
        int id = wareHouse.getNewId("order");
        Order *newOrder = new Order(id, customerId, customer->getCustomerDistance());
        customer->addOrder(id);
        wareHouse.addOrder(newOrder);
        complete();
    }
    wareHouse.addAction(this);
};

string AddOrder::toString() const {
    ActionStatus actionStatus = getStatus();
    if (actionStatus == ActionStatus::COMPLETED) {
        return "order " + std::to_string(customerId) + " COMPLETED";
    } 
    else{
        return "order " + std::to_string(customerId) + " ERROR";
    }
};
