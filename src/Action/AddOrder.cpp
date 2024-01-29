#include "../../include/Action.h" 

AddOrder::AddOrder(int id):
customerId(id){};

AddOrder* AddOrder::clone() const {
    return new AddOrder(*this);
};


void AddOrder::act(WareHouse &wareHouse) {
    if((!wareHouse.isCustomerExist(customerId)) || !wareHouse.getCustomer(customerId).canMakeOrder()){
        error("Cannot place this order");
        std::cout << "Error: " + getErrorMsg() << endl;
    }
    else{

        int orderId = wareHouse.newOrderId();
        int distance = wareHouse.getCustomer(customerId).getCustomerDistance();
        Order* newOrder = new Order(orderId, customerId, distance);
        wareHouse.getCustomer(customerId).addOrder(orderId);
        wareHouse.addOrder(newOrder);
    }
    wareHouse.addAction(this);
};
// void AddOrder::act(WareHouse &wareHouse) {
//     if (!wareHouse.isCustomerExsist(customerId)){

//     }
//     else
//     {
//         Customer *C = &wareHouse.getCustomer(customerId);
//         if (!C->canMakeOrder())
//         {
            
//         }
//         int id = wareHouse.getnewid("order");
//         Order *newOrder = new Order(id, customerId, C->getCustomerDistance());
//         C->addOrder(id);
//         wareHouse.addOrder(newOrder);
//     }
// };

string AddOrder::toString() const {

};

