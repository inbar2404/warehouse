#include "../../include/Action.h" 
#include <iostream>

// PrintCustomerStatus::PrintCustomerStatus(int customerId) : customerId(customerId){};

// PrintCustomerStatus *PrintCustomerStatus::clone() const{
//     return new PrintCustomerStatus(*this);
// };

// void PrintCustomerStatus::act(WareHouse &wareHouse) {
//     if(!wareHouse.isCustomerExist(customerId)){
//         error("Customer doesn't exist");
//         std::cout << "Error: " + getErrorMsg() << endl;
//         this->setStatus(ActionStatus::ERROR);
//     }
//     else{
//         //ROTEM
//         // std::cout << "CustomerID: " + to_string(customerId) << endl;
//         // Customer Cust = WareHouse.getCustomer(customerId);
//         // vector<int> ordersIds = Cust.getOrdersIds();
//         // for(int id:ordersIds){
//         //     std::cout << "OrderID: " + to_string(id) << endl ;
//         //     std::cout << "OrderStatus: " + wareHouse.getOrder(id).StatusStr() << endl;
//         // }
//         // std::cout << "numOrdersLeft: "<< Cust.getOrdersLeft()  << std::endl;
//     }
//     wareHouse.addAction(this);
//     this->setStatus(ActionStatus::COMPLETED);
// };

// string PrintCustomerStatus::toString() const {
//     ActionStatus actionStatus = getStatus();
//     if (actionStatus == ActionStatus::COMPLETED) {
//         return "customerStatus " + std::to_string(customerId) + " COMPLETED";
//     } else {
//         return "customerStatus " + std::to_string(customerId) + " ERROR";
//     }
//};