#include "../../include/Action.h" 
#include <sstream>
#include <iostream>

Close::Close() {}

void Close::act(WareHouse &wareHouse)
{
    std::stringstream str;
    std::cout << str.str();
    wareHouse.close(); //close the warehouse and exit main loop
    complete();
    wareHouse.addAction(this);
}

Close *Close::clone() const
{
    return new Close(*this);
}

string Close::toString() const
{
    // ROTEM: I think you should print all orders' logs (look at the running example) -> ant to call it from the act?
    return "close COMPLETED";
}