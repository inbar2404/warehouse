#include "../../include/Action.h" 

AddOrder::AddOrder(int id): BaseAction() {};

AddOrder* AddOrder::clone() const {
    // override(?)
    return new AddOrder(*this);
};


void AddOrder::act(WareHouse &wareHouse) override () {
    
}

string AddOrder::toString() const override() {

};

