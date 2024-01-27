#include "../../include/Action.h" 

PrintActionsLog::PrintActionsLog(){};

PrintActionsLog* PrintActionsLog:: clone() const{
    return new PrintActionsLog(*this);
};

void PrintActionsLog::act(WareHouse &wareHouse) {

};

string PrintActionsLog::toString() const {

};