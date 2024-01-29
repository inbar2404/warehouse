#include "../../include/Action.h" 
#include <sstream>
#include <iostream>

// ROTEM
Close::Close() {}

void Close::act(WareHouse &wareHouse)
{
//     std::stringstream str;
//     std::cout << str.str();
//     //close the warehouse and exit main loop
//     wareHouse.close();
//     this->setStatus(ActionStatus::COMPLETED);
}

Close *Close::clone() const
{
    return new Close(*this);
}

string Close::toString() const
{
    return "close COMPLETED";
}