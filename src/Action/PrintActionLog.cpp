#include "../../include/Action.h" 
#include <sstream>
#include <iostream>

PrintActionsLog::PrintActionsLog(){};

PrintActionsLog* PrintActionsLog:: clone() const{
    return new PrintActionsLog(*this);
};

void PrintActionsLog::act(WareHouse &wareHouse) {
    std::stringstream str;   
    std::vector<BaseAction*> actions = wareHouse.getActions();
    for(BaseAction* action : actions){
        str << action->toString() << std::endl;
    }
    std::cout << str.str() ;
    complete();
    wareHouse.addAction(this); 
};

string PrintActionsLog::toString() const {
    return "log COMPLETED";
};