#include "../../include/Action.h" 

AddCustomer::AddCustomer(string customerName, string customerType, int distance, int maxOrders)
    : BaseAction() {};

AddCustomer *clone() const {
// override(?)
    return new AddCustomer(*this);
};

void AddCustomer::act(WareHouse &wareHouse) override () {
    cin >>  customer <customer_name> <customer_type> <customer_distance> <max_orders>;
    Customer NewCustomer = Customer(customerCounter,this->customerName, this->customerType, this->distance, this->maxOrders);
    customerCounter ++;
    Customers.push_back(NewCustomer);
};

string AddCustomer::toString() const override () {

};