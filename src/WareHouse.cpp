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

vector<Order*>& WareHouse::getFinishCollectOrders() const {
    vector<Order*> requetedOrders;
    for (auto &order : inProcessOrders)
    {
        int collectorId = order->getCollectorId();
        Volunteer* collector = &getVolunteer(collectorId);
        if (collector->getCompletedOrderId() == order->getId()){
            requetedOrders.push_back(order);
        }
    }
    return requetedOrders;
};

vector<Volunteer*>& WareHouse::getvolunteersInAction() const {
    vector<Volunteer*> requetedVolunteers;
    for (auto &volunteer : volunteers)
    {
        // TODO: Find out if thats the accurate required check
        if (volunteer->getActiveOrderId() != NO_ORDER && volunteer->getActiveOrderId() != volunteer->getCompletedOrderId()){
            requetedVolunteers.push_back(volunteer);
        }
    }
    return requetedVolunteers;
};

void WareHouse::removeLimitedVolunteersReachingMax() const {};