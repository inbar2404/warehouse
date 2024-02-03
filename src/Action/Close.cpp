#include "../../include/Action.h" 
#include <sstream>
#include <iostream>

Close::Close() {}

void Close::act(WareHouse &wareHouse)
{
    // Print all orders by their id
    vector<Order*> orders = wareHouse.getOrders();
    std::stringstream str;
    for(Order *order : orders){
        str << "OrderID: " << order->getId();
        str << ", CustomerID: " << order->getCustomerId();
        str << ", OrderStatus: " << (order->getStatusName()) << std::endl;
    }
    std::cout << str.str();
    wareHouse.close(); // Close the warehouse and exit main loop
    wareHouse.addAction(this);
    complete();
}

Close *Close::clone() const
{
    return new Close(*this);
}

string Close::toString() const
{
    return "close COMPLETED";
}