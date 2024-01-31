#include "../include/WareHouse.h" 
#include <iostream>
using namespace std;
#include <algorithm> // for std::remove
#include <fstream>
#include <sstream>
#include <stdexcept> // For std::invalid_argument
#include "Parser.h"


WareHouse::WareHouse(const string &configFilePath) {
    ifstream configFile(configFilePath);

    // Check if file open as expected
    if (!configFile.is_open()) {
        throw std::invalid_argument("Configuration file was not found");
    }

    // Init counters
    volunteerCounter = 0;
    customerCounter = 0;
    orderCounter = 0;

    Parser::parseConfigFile(*this, configFile);

    configFile.close();
}

// TODO: Check that the functions belong to the rule of 5 works well (find a way to do that) 
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

    // TODO: Find out why is that doing problems (in backup 2 example)
    // if (other.defaultCustomer) {
    //     defaultCustomer = other.defaultCustomer->clone();
    // }

    // if (other.defaultVolunteer) {
    //     defaultVolunteer = other.defaultVolunteer->clone();
    // }

    // if (other.defaultOrder) {
    //     defaultOrder = other.defaultOrder->clone();
    // }
};

// TODO: Compare this method with another resource
WareHouse::WareHouse(WareHouse&& other) {
    pendingOrders = std::move(other.pendingOrders);
    inProcessOrders = std::move(other.inProcessOrders);
    completedOrders = std::move(other.completedOrders);
    customers = std::move(other.customers);
    volunteers = std::move(other.volunteers);
    actionsLog = std::move(other.actionsLog);

    defaultCustomer = &other.getDefaultCustomer();
    other.defaultCustomer = nullptr;

    defaultVolunteer = &other.getDefaultVolunteer();
    other.defaultVolunteer = nullptr;

    defaultOrder = &other.getDefaultOrder();
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

        // TODO: Find out why it is do problem when calling for restore (second call example 2)
        // defaultCustomer = other.defaultCustomer->clone();
        // defaultVolunteer = other.defaultVolunteer->clone();
        // defaultOrder = other.defaultOrder->clone();

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

        defaultCustomer = &other.getDefaultCustomer();
        defaultVolunteer = &other.getDefaultVolunteer();
        defaultOrder = &other.getDefaultOrder();

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

// ROTEM: Find out why is it doing problem when calling to close() in the second example from second file
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

    // TODO: Find out why is doing problem in the close
    // delete defaultCustomer;
    // delete defaultVolunteer;
    // delete defaultOrder;

    pendingOrders.clear();
    inProcessOrders.clear();
    completedOrders.clear();
    customers.clear();
    volunteers.clear();
    actionsLog.clear();
};

void WareHouse::start()
{
    open();
    std::cout << "Warehouse is open!" << std::endl;

    while (isOpen)
    {
        string actionName;
        string input;

         std::getline(std::cin, input);
         std::stringstream ss(input);
         ss >> actionName;

        if (actionName == "step")
        {
            int numOfSteps;
            ss >> numOfSteps;
            SimulateStep *step = new SimulateStep(numOfSteps);
            step->act(*this);
        }
        else if (actionName == "order")
        {
            int customerID;
            ss >> customerID;
            AddOrder *addOrder = new AddOrder(customerID);
            addOrder->act(*this);
        }
        else if (actionName == "customer")
        {
            string customerName;
            ss >> customerName;
            string CustomerType;
            ss >> CustomerType;
            int distance;
            ss >> distance;
            int maxOrders;
            ss >> maxOrders;
            AddCustomer *addCustomer = new AddCustomer(customerName,CustomerType, distance,maxOrders);
            addCustomer->act(*this);
        }
        else if (actionName == "orderStatus")
        {
            int orderID;
            ss >> orderID;
            PrintOrderStatus *printOrder = new PrintOrderStatus(orderID);
            printOrder->act(*this);
        }
        else if (actionName == "customerStatus")
        {
            int customerID;
            ss >> customerID;
            PrintCustomerStatus *customerstatus = new PrintCustomerStatus(customerID);
            customerstatus->act(*this);
        }
        else if (actionName == "volunteerStatus")
        {
            int volunteerID;
            ss >> volunteerID;
            PrintVolunteerStatus *printvolunteer = new PrintVolunteerStatus(volunteerID);
            printvolunteer->act(*this);
        }
        else if (actionName == "log")
        {
            PrintActionsLog *log = new PrintActionsLog();
            log->act(*this);
        }
        else if (actionName == "close")
        {
            Close *close = new Close();
            close->act(*this);
        }
        else if (actionName == "backup")
        {
            BackupWareHouse* backup = new BackupWareHouse();
            backup->act(*this);
        }
        else if (actionName == "restore")
        {
            RestoreWareHouse* restore = new RestoreWareHouse();
            restore->act(*this);
        }
        else
        {
            std::cout << "action doesn't exist" << std::endl;
        }
    }
};

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
    return getDefaultCustomer();
};

Volunteer& WareHouse::getVolunteer(int volunteerId) const {
    for (Volunteer* volunteer : volunteers)
    {
        if (volunteer->getId() == volunteerId) {
            return *volunteer;
        }
    }
    // If volunteer not found, return a default Volunteer.
    return getDefaultVolunteer();
};

Order* WareHouse::getOrderPointer(int orderId) const {
    // Merge all types of orders into one vector
    vector<Order*> orders; 
    orders.insert(orders.end(), pendingOrders.begin(), pendingOrders.end());
    orders.insert(orders.end(), inProcessOrders.begin(), inProcessOrders.end());
    orders.insert(orders.end(), completedOrders.begin(), completedOrders.end());

    for (Order* &order : orders) {
        if (order->getId() == orderId) {
            return order;
        }
    }

    // If order not found, return nullptr.
    return nullptr;
};

Order& WareHouse::getOrder(int orderId) const {
    Order* order = getOrderPointer(orderId);
    if (order != nullptr){
        return *order;
    }    
    return getDefaultOrder();   // If order not found, return a default order.
};

const vector<BaseAction*>& WareHouse::getActions() const {
    return actionsLog;
};

void WareHouse::close() {
    isOpen = false;
};

void WareHouse::open() {
    isOpen = true;
};

const vector<Volunteer*>& WareHouse::getVolunteers() const {
    return volunteers;
};

const vector<Order*>& WareHouse::getPendingOrders() const {
    return pendingOrders;
};

vector<Order*> WareHouse::getFinishCollectOrders() const {
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

void WareHouse::removeLimitedVolunteersReachingMax() {
    vector<Volunteer*> volunteersToRemove;
    for (Volunteer* volunteer : volunteers) {
        if ((typeid(*volunteer) == typeid(LimitedDriverVolunteer) ||
             typeid(*volunteer) == typeid(LimitedCollectorVolunteer)) &&
            (!(volunteer->hasOrdersLeft() || volunteer->isBusy()))) {
            volunteersToRemove.push_back(volunteer);
        }
    }

    for (Volunteer* volunteer : volunteersToRemove) {
        volunteers.erase(
            std::remove_if(
                volunteers.begin(),
                volunteers.end(),
                [volunteer](const Volunteer* v) { return v == volunteer; }
            ),
            volunteers.end()
        );
    }
};

void WareHouse::removeFromList(Order* order, string listName) {
    if (listName == "pending")
    {
        pendingOrders.erase(
            std::remove_if(
                pendingOrders.begin(),
                pendingOrders.end(),
                [order](const Order* o) { return o == order; }
            ),
            pendingOrders.end()
        );
    }
    if (listName == "inProcess"){
        inProcessOrders.erase(
            std::remove_if(
                inProcessOrders.begin(),
                inProcessOrders.end(),
                [order](const Order* o) { return o == order; }
            ),
            inProcessOrders.end()
        );
    }
};

int WareHouse::getNewId(string counterType) {
    int id;
    if (counterType == "customer"){
        id = customerCounter;
        customerCounter++;
    }
    else if (counterType == "volunteer")
    {
        id = volunteerCounter;
        volunteerCounter++;
    }
    else if(counterType == "order")
    {
        id = orderCounter;
        orderCounter++;
    }
    return id;
};

void WareHouse::addCustomer(Customer* customer){
    if (customer != nullptr){
        customers.push_back(customer);
    }
};

void WareHouse::addVolunteer(Volunteer* volunteer){
    if (volunteer != nullptr){
        volunteers.push_back(volunteer);
    }
};

Customer& WareHouse::getDefaultCustomer() const {
    return *defaultCustomer;
};

Volunteer& WareHouse::getDefaultVolunteer() const {
    return *defaultVolunteer;
};

Order& WareHouse::getDefaultOrder() const {
    return *defaultOrder;
};

vector<Order*> WareHouse::getVOrders() const{
    vector<Order*> OrdersVec = this->getPendingOrders();
    OrdersVec.insert(OrdersVec.end(), this->inProcessOrders.begin(), this->inProcessOrders.end());
    OrdersVec.insert(OrdersVec.end(), this->completedOrders.begin(), this->completedOrders.end());
    // OrdersVec.push_back(this->inProcessOrders);
    // OrdersVec.push_back(this->completedOrders);
    return OrdersVec;
};