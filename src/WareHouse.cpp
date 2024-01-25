#include "../include/WareHouse.h" 


// TODO: Implement all methods in file

WareHouse::WareHouse(const string &configFilePath) {};

void WareHouse::start() {};

void WareHouse::addOrder(Order* order) {};

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

const vector<BaseAction*>& WareHouse::getActions() const {};

void WareHouse::close() {};

void WareHouse::open() {};

vector<Order*>& WareHouse::getPendingOrders() {
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
        // TODO: Find out if thats the accurate required check
        if (volunteer->getActiveOrderId() != NO_ORDER && volunteer->getActiveOrderId() != volunteer->getCompletedOrderId()){
            requetedVolunteers.push_back(volunteer);
        }
    }
    return requetedVolunteers;
};

void WareHouse::removeLimitedVolunteersReachingMax() const {};