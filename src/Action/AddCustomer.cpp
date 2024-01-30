#include "../../include/Action.h" 
#include "../../include/Customer.h" 
#include <iostream>

AddCustomer::AddCustomer(std::string customerName, std::string customerType, int distance, int maxOrders)
    : BaseAction(), customerName(customerName), distance(distance), maxOrders(maxOrders), customerType(customerType=="soldier"? CustomerType::Soldier : CustomerType::Civilian) {};

AddCustomer* AddCustomer::clone() const {
    return new AddCustomer(*this);
};

void AddCustomer::act(WareHouse &wareHouse) {
    Customer *newCustomer = wareHouse.defaultCustomer;
    int counter = wareHouse.getNewId("customer");
    if (customerType == CustomerType::Civilian){
        CivilianCustomer *newCustomer = new CivilianCustomer(counter, customerName, distance, maxOrders);
    }
    else{
        SoldierCustomer *newCustomer = new SoldierCustomer(counter, customerName, distance, maxOrders);
    }
    wareHouse.addCustomer(newCustomer);
    wareHouse.addAction(this);
    this->setStatus(ActionStatus::COMPLETED);
};

std::string AddCustomer::toString() const {
    // // Provide implementation for toString if needed
    if(customerType == CustomerType::Soldier)
    {
        return "customer " + customerName +  " soldier " + std::to_string(distance) +" " + std::to_string(maxOrders) + " COMPLETED";
    }
    else
    {
        return "customer " + customerName +  " civilian " + std::to_string(distance) +" " + std::to_string(maxOrders) + " COMPLETED";
    }
};