#include "../include/WareHouse.h" 
#include <iostream>
using namespace std;
#include <algorithm> // for std::remove
#include "../include/Action.h"


WareHouse::WareHouse(const string &configFilePath) {
    // TODO: Read data from the config file and init objects by the given data
};

WareHouse::WareHouse(const WareHouse &other)
    : isOpen(other.isOpen), customerCounter(other.customerCounter),
      volunteerCounter(other.volunteerCounter), defaultCustomer(nullptr),
      defaultVolunteer(nullptr), defaultOrder(nullptr) {

    for (const Customer* customer : other.customers) {
        customers.push_back(customer->clone());
    }

    for (const Volunteer* volunteer : other.volunteers) {
        volunteers.push_back(volunteer->clone());
    }

    for (const Order* order : other.pendingOrders) {
        pendingOrders.push_back(order->clone());
    }

    for (const Order* order : other.inProcessOrders) {
        inProcessOrders.push_back(order->clone());
    }

    for (const Order* order : other.completedOrders) {
        completedOrders.push_back(order->clone());
    }

    for (const BaseAction* action : other.actionsLog) {
        actionsLog.push_back(action->clone());
    }

    if (other.defaultCustomer) {
        defaultCustomer = other.defaultCustomer->clone();
    }

    if (other.defaultVolunteer) {
        defaultVolunteer = other.defaultVolunteer->clone();
    }

    if (other.defaultOrder) {
        defaultOrder = other.defaultOrder->clone();
    }
};

// TODO: Check this method with another resource
WareHouse::WareHouse(WareHouse&& other) {
    pendingOrders = std::move(other.pendingOrders);
    inProcessOrders = std::move(other.inProcessOrders);
    completedOrders = std::move(other.completedOrders);
    customers = std::move(other.customers);
    volunteers = std::move(other.volunteers);
    actionsLog = std::move(other.actionsLog);

    defaultCustomer = other.defaultCustomer;
    other.defaultCustomer = nullptr;

    defaultVolunteer = other.defaultVolunteer;
    other.defaultVolunteer = nullptr;

    defaultOrder = other.defaultOrder;
    other.defaultOrder = nullptr;

    isOpen = other.isOpen;
    customerCounter = other.customerCounter;
    volunteerCounter = other.volunteerCounter;

    other.pendingOrders.clear();
    other.inProcessOrders.clear();
    other.completedOrders.clear();
    other.customers.clear();
    other.volunteers.clear();
};
        
// TODO: Compare with another resource if a delete is required
WareHouse& WareHouse::operator=(const WareHouse &other) {
    if (this != &other) { 
        pendingOrders = other.pendingOrders;
        inProcessOrders = other.inProcessOrders;
        completedOrders = other.completedOrders;
        customers = other.customers;
        volunteers = other.volunteers;
        actionsLog = other.actionsLog;

        defaultCustomer = other.defaultCustomer->clone();
        defaultVolunteer = other.defaultVolunteer->clone();
        defaultOrder = other.defaultOrder->clone();

        isOpen = other.isOpen;
        customerCounter = other.customerCounter;
        volunteerCounter = other.volunteerCounter;
    }

    return *this;
};

WareHouse& WareHouse::operator=(WareHouse&& other) {
    if (this != &other) { 
        pendingOrders = std::move(other.pendingOrders);
        inProcessOrders = std::move(other.inProcessOrders);
        completedOrders = std::move(other.completedOrders);
        customers = std::move(other.customers);
        volunteers = std::move(other.volunteers);
        actionsLog = std::move(other.actionsLog);

        defaultCustomer = other.defaultCustomer;
        defaultVolunteer = other.defaultVolunteer;
        defaultOrder = other.defaultOrder;

        // TODO: Compare this half function with another resource
        other.defaultCustomer = nullptr;
        other.defaultVolunteer = nullptr;
        other.defaultOrder = nullptr;

        isOpen = other.isOpen;
        customerCounter = other.customerCounter;
        volunteerCounter = other.volunteerCounter;

        other.isOpen = false;
        other.customerCounter = 0;
        other.volunteerCounter = 0;
    }

    return *this;
};

WareHouse::~WareHouse() {   
    for (Order* order : pendingOrders) {
        delete order;
    }
    for (Order* order : inProcessOrders) {
        delete order;
    }
    for (Order* order : completedOrders) {
        delete order;
    }
    for (Customer* customer : customers) {
        delete customer;
    }
    for (Volunteer* volunteer : volunteers) {
        delete volunteer;
    }
    for(BaseAction* action: actionsLog) {
        delete action;
    }

    delete defaultCustomer;
    delete defaultVolunteer;
    delete defaultOrder;

    pendingOrders.clear();
    inProcessOrders.clear();
    completedOrders.clear();
    customers.clear();
    volunteers.clear();
    actionsLog.clear();
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

const vector<Volunteer*>& WareHouse::getVolunteers() const {
    return volunteers;
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

// TODO: Think about better implementation for this function 
void WareHouse::removeLimitedVolunteersReachingMax() {
    vector<Volunteer*> volunteersToRemove;
    for (Volunteer* volunteer : volunteers) {
        if ((typeid(*volunteer) == typeid(LimitedDriverVolunteer) ||
             typeid(*volunteer) == typeid(LimitedCollectorVolunteer)) &&
            volunteer->hasOrdersLeft()) {
            volunteersToRemove.push_back(volunteer);
        }
    }

    for (Volunteer* volunteer : volunteersToRemove) {
        volunteers.erase(remove(volunteers.begin(), volunteers.end(), volunteer), volunteers.end());
    }
};

// TODO: Make this function better
void WareHouse::removeFromList(Order* order, string listName) {
    if (listName == "pending")
    {
        pendingOrders.erase(
            std::remove(pendingOrders.begin(), pendingOrders.end(), order),
            pendingOrders.end()
        );
    }
    if (listName == "inProcess"){
        inProcessOrders.erase(
        std::remove(inProcessOrders.begin(), inProcessOrders.end(), order),
        inProcessOrders.end()
    );
    }
};