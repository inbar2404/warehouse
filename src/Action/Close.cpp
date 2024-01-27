#include "../../include/Action.h" 
#include <sstream>
#include <iostream>

// TODO: Check this file
Close::Close() {}

void Close::act(WareHouse &wareHouse)
{
    std::stringstream str;
    std::cout << str.str();
    //close the warehouse and exit main loop
    wareHouse.close();
}

Close *Close::clone() const
{
    return new Close(*this);
}
string Close::toString() const
{
    return "close COMPLETED";
}