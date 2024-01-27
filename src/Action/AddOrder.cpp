#include "../../include/Action.h" 

AddOrder::AddOrder(int id):
customerId(id){};

AddOrder* AddOrder::clone() const {
    // override(?)
    return new AddOrder(*this);
};


void AddOrder::act(WareHouse &wareHouse) {
    
};

string AddOrder::toString() const {

};

