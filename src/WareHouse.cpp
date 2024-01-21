#include "../include/WareHouse.h" 


// TODO: Implement all methods in file

WareHouse::WareHouse(const string &configFilePath) {};

void WareHouse::start() {};

void WareHouse::addOrder(Order* order) {};

void WareHouse::addAction(BaseAction* action) {};

Customer& WareHouse::getCustomer(int customerId) const {};

Volunteer& WareHouse::getVolunteer(int volunteerId) const {};

Order& WareHouse::getOrder(int orderId) const {};

const vector<BaseAction*>& WareHouse::getActions() const {};

void WareHouse::close() {};

void WareHouse::open() {};

vector<Order*>& WareHouse::getPendingOrders() const {};

vector<Order*>& WareHouse::getFinishCollectOrders() const {};

vector<Volunteer*>& WareHouse::getvolunteersInAction() const {};

void WareHouse::removeLimitedVolunteersReachingMax() const {};