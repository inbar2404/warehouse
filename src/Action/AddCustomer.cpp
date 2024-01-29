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
    // int counter = wareHouse.getNewId("customer");
    // //Customer newCustomer = new Customer(counter, customerName, customerType, distance, maxOrders);
    // // customerCounter++;
    // //ROTEM
    // //wareHouse.AddCustomer(newCustomer);
    // wareHouse.addAction(this);
    // this->setStatus(ActionStatus::COMPLETED);
};

// ROTEM
std::string AddCustomer::toString() const {
    // // Provide implementation for toString if needed
    // if(customerType == CustomerType::Soldier)
    // {
    //     return "customer " + customerName +  " soldier " + std::to_string(distance) +" " + std::to_string(maxOrders) + " COMPLETED";
    // }
    // else
    // {
    //     return "customer " + customerName +  " civilian " + std::to_string(distance) +" " + std::to_string(maxOrders) + " COMPLETED";
    // }
};