#include "../../include/Customer.h" 

SoldierCustomer(int id, string name, int locationDistance, int maxOrders)
 : customer(id, name, locationDistance, maxOrders) {};

SoldierCustomer* SoldierCustomer::clone() const {
    return new SoldierCustomer(*this);
};
