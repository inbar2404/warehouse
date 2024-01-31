#include "../../include/Action.h" 
#include <sstream>
#include <iostream>

Close::Close() {}

void Close::act(WareHouse &wareHouse)
{
    vector<Order*> orderVec = wareHouse.getVOrders();
    std::stringstream str;
    for(Order *O : orderVec){
        str << "OrderID: " << O->getId();
        str << ", CustomerID: " << O->getCustomerId();
        str << ", OrderStatus: " << (O->getStatusName()) << std::endl;
    }
    std::cout << str.str();
    wareHouse.close(); // Close the warehouse and exit main loop
    wareHouse.addAction(this);
    this->setStatus(ActionStatus::COMPLETED);
}

Close *Close::clone() const
{
    return new Close(*this);
}

string Close::toString() const
{
    return "close COMPLETED";
}