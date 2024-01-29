#include "../../include/Action.h" 
#include <iostream>

AddOrder::AddOrder(int id):
customerId(id){};

AddOrder* AddOrder::clone() const {
    return new AddOrder(*this);
};

// void AddOrder::act(WareHouse &wareHouse) {
//     if((!wareHouse.isCustomerExist(customerId)) || !wareHouse.getCustomer(customerId).canMakeOrder()){
//         error("Cannot place this order");
//         std::cout << "Error: " + getErrorMsg() << endl;
//     }
//     else{

//         int orderId = wareHouse.newOrderId();
//         int distance = wareHouse.getCustomer(customerId).getCustomerDistance();
//         Order* newOrder = new Order(orderId, customerId, distance);
//         wareHouse.getCustomer(customerId).AddOrder(orderId);
//         wareHouse.AddOrder(newOrder);
//     }
//     wareHouse.addAction(this);
// };

void AddOrder::act(WareHouse &wareHouse) {
    Customer *customer = &wareHouse.getCustomer(customerId);
    if (customer==wareHouse.defaultCustomer || !customer->canMakeOrder()) //  Handle a case customer was not found 
    {
        error("Cannot place this order");
        std::cout << "Error: " + getErrorMsg() << endl;
        // this->setStatus(ActionStatus::ERROR); // ROTEM
    }
    else
    {
        int id = wareHouse.getNewId("order");
        Order *newOrder = new Order(id, customerId, customer->getCustomerDistance());
        customer->addOrder(id);
        wareHouse.addOrder(newOrder);
        wareHouse.addAction(this);
        // this->setStatus(ActionStatus::COMPLETED); // ROTEM
    }
};

string AddOrder::toString() const {
    // ActionStatus actionStatus = getStatus();
    // if (actionStatus == ActionStatus::COMPLETED) {
    //     return "order " + std::to_string(customerId) + " COMPLETED";
    // } 
    // else{
    //     return "order " + std::to_string(customerId) + " ERROR";
    // }
};
