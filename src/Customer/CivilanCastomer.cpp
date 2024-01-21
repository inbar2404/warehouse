#include "../../include/Customer.h" 

CivilianCustomer(int id, string name, int locationDistance, int maxOrders)
 : customer(id, name, locationDistance, maxOrders) {};

CivilianCustomer* CivilianCustomer::clone() const {
    return new CivilianCustomer(*this);
};
