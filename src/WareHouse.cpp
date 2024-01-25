#include "../include/WareHouse.h" 
#include <iostream>
using namespace std;

// TODO: Dont forget to find out what is the rule of 5 and do rellvant implemantations
WareHouse::WareHouse(const string &configFilePath) {
    // TODO: Read data from the config file and init objects by the given data
};

// TODO: Implement
void WareHouse::start() {};

// TODO: Implement
void WareHouse::addOrder(Order* order) {};

// TODO: Implement
void WareHouse::addAction(BaseAction* action) {};

Customer& WareHouse::getCustomer(int customerId) const {
    for (auto &customer : customers)
    {
        if (customer->getId() == customerId) {
            return *customer;
        }
    }
    // TODO: Find out if I've to return a flag if no customer found
};

Volunteer& WareHouse::getVolunteer(int volunteerId) const {
    for (auto &volunteer : volunteers)
    {
        if (volunteer->getId() == volunteerId) {
            return *volunteer;
        }
    }
    // TODO: Find out if I've to return a flag if no volunteer found
};

Order& WareHouse::getOrder(int orderId) const {
    // Merge all types of orders into one vector
    vector<Order*> orders; 
    orders.insert(orders.end(), pendingOrders.begin(), pendingOrders.end());
    orders.insert(orders.end(), inProcessOrders.begin(), inProcessOrders.end());
    orders.insert(orders.end(), completedOrders.begin(), completedOrders.end());

    for (auto &order : orders)
    {
        if (order->getId() == orderId) {
            return *order;
        }
    }
    // TODO: Find out if I've to return a flag if no volunteer found
};

const vector<BaseAction*>& WareHouse::getActions() const {
    return actionsLog;
};

void WareHouse::close() {
    // TODO: Find out - is that all what needed in this function?
    isOpen = false;
};

void WareHouse::open() {
    // TODO: Find out - is that all what needed in this function?
    isOpen = true;
    cout << "Warehouse is open!" << endl;
};

const vector<Order*>& WareHouse::getPendingOrders() const {
    return pendingOrders;
};

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
        // TODO: Find out if thats the accurate required check -> I think it should be with isBusy (check examples in gitHub)
        if (volunteer->getActiveOrderId() != NO_ORDER && volunteer->getActiveOrderId() != volunteer->getCompletedOrderId()){
            requetedVolunteers.push_back(volunteer);
        }
    }
    return requetedVolunteers;
};

// TODO: Implement
void WareHouse::removeLimitedVolunteersReachingMax() const {};

// TODO: Implement
CollectorVolunteer WareHouse::getAvailableCollector() const {};

// TODO: Implement
DriverVolunteer WareHouse::getAvailableDriver() const {};