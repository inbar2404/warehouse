#include "../../include/Action.h" 
#include "../../include/Customer.h" 
#include <iostream>

AddCustomer::AddCustomer(std::string customerName, std::string customerType, int distance, int maxOrders)
    : BaseAction(), customerName(customerName), distance(distance), maxOrders(maxOrders), customerType(customerType=="soldier"? CustomerType::Soldier : CustomerType::Civilian) {};

AddCustomer* AddCustomer::clone() const {
    return new AddCustomer(*this);
};

// ROTEM
void AddCustomer::act(WareHouse &wareHouse) {
    // int counter = wareHouse.customerCounter;
    // Customer newCustomer = Customer(counter, customerName, customerType, distance, maxOrders);
    // customerCounter++;
    // wareHouse.addCustomer(newCustomer);
};

// ROTEM
std::string AddCustomer::toString() const {
    // Provide implementation for toString if needed
    return "";
};