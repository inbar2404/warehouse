#include "../../include/Action.h" 

PrintActionsLog::PrintActionsLog(string customerName, string customerType, int distance, int maxOrders)
    : BaseAction() {};

PrintActionsLog *clone() const {
// override(?)
    return new PrintActionsLog(*this);
};

void PrintActionsLog::act(WareHouse &wareHouse) override () {

};

string PrintActionsLog::toString() const override () {

};