#include "../../include/Action.h" 

AddOrder::AddOrder(int id):
customerId(id){};

AddOrder* AddOrder::clone() const {
    // override(?)
    return new AddOrder(*this);
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

