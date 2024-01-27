#include "../include/WareHouse.h" 
#include <iostream>
using namespace std;

// TODO: Dont forget to find out what is the rule of 5 and do rellvant implemantations
WareHouse::WareHouse(const string &configFilePath) {
    // TODO: Read data from the config file and init objects by the given data
};

// TODO: Implement
void WareHouse::start() {};

void WareHouse::addOrder(Order* order) {
    // Check the order status and add the order to the correct vector
    switch (order->getStatus()) {
        case OrderStatus::PENDING:
            pendingOrders.push_back(order);
            break;
        case OrderStatus::COLLECTING:
        case OrderStatus::DELIVERING:
            inProcessOrders.push_back(order);
            break;
        case OrderStatus::COMPLETED:
            completedOrders.push_back(order);
            break;
        default: // Handle other statuses if needed
            break;
    }
};

void WareHouse::addAction(BaseAction* action) {
    actionsLog.push_back(action);
};

Customer& WareHouse::getCustomer(int customerId) const {
    for (Customer* customer : customers)
    {
        if (customer->getId() == customerId) {
            return *customer;
        }
    }
    // If customer not found, return a default customer.
    return *defaultCustomer;
};

Volunteer& WareHouse::getVolunteer(int volunteerId) const {
    for (Volunteer* volunteer : volunteers)
    {
        if (volunteer->getId() == volunteerId) {
            return *volunteer;
        }
    }
    // If volunteer not found, return a default Volunteer.
    return *defaultVolunteer;
};

Order& WareHouse::getOrder(int orderId) const {
    // Merge all types of orders into one vector
    vector<Order*> orders; 
    orders.insert(orders.end(), pendingOrders.begin(), pendingOrders.end());
    orders.insert(orders.end(), inProcessOrders.begin(), inProcessOrders.end());
    orders.insert(orders.end(), completedOrders.begin(), completedOrders.end());

    for (Order* &order : orders)
    {
        if (order->getId() == orderId) {
            return *order;
        }
    }
    
    // If order not found, return a default order.
    return *defaultOrder;
};

const vector<BaseAction*>& WareHouse::getActions() const {
    return actionsLog;
};

void WareHouse::close() {
    isOpen = false;
};

void WareHouse::open() {
    isOpen = true;
    cout << "Warehouse is open!" << endl;
};

const vector<Order*>& WareHouse::getPendingOrders() const {
    return pendingOrders;
};

vector<Order*>& WareHouse::getFinishCollectOrders() const {
    vector<Order*> requetedOrders;
    for (Order* order : inProcessOrders)
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
    for (Volunteer* volunteer : volunteers)
    {
        // TODO: Find out if thats the accurate required check -> I think it should be with isBusy (check examples in gitHub)
        if (volunteer->getActiveOrderId() != NO_ORDER && volunteer->getActiveOrderId() != volunteer->getCompletedOrderId()){
            requetedVolunteers.push_back(volunteer);
        }
    }
    return requetedVolunteers;
};


// TODO: Implement
void WareHouse::removeOrder(Order* order) const {

};

// TODO: Implement
void WareHouse::removeLimitedVolunteersReachingMax() const {};

// TODO: Implement
CollectorVolunteer WareHouse::getAvailableCollector() const {};

// TODO: Implement
DriverVolunteer WareHouse::getAvailableDriver() const {};