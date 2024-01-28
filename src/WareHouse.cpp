#include "../include/WareHouse.h" 
#include <iostream>
using namespace std;
#include <algorithm> // for std::remove
#include <fstream>
#include <sstream>
#include <stdexcept> // For std::invalid_argument


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

    parseConfigFile(configFile);

    configFile.close();
}

// TODO: If I have enough time - rename variables and move to a diffrent file (same for 2 next methods)
void WareHouse::parseConfigFile(ifstream& configFile) {
    string line;
    while (getline(configFile, line)) {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Use a stringstream to parse the line
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "customer") {
            parseCustomer(ss);
        } else if (command == "volunteer") {
            parseVolunteer(ss);
        } else {
            throw std::invalid_argument("Unkown command");
        }
    }
}

void WareHouse::parseCustomer(stringstream& ss) {
    string customerName, customerTypeStr;
    int distance, maxOrders;

    ss >> customerName >> customerTypeStr >> distance >> maxOrders;

    // Convert customerTypeStr to CustomerType enum
    CustomerType customerType;
    if (customerTypeStr == "soldier") {
        customerType = CustomerType::Soldier;
        customers.push_back(new SoldierCustomer(customerCounter, customerName, distance, maxOrders));
    } else if (customerTypeStr == "civilian") {
        customerType = CustomerType::Civilian;
        customers.push_back(new CivilianCustomer(customerCounter, customerName, distance, maxOrders));
    } else {
        throw std::invalid_argument("Invalid customer type");
    }
    customerCounter++; // Add one to the customer counter
}

void WareHouse::parseVolunteer(stringstream& ss) {
    string volunteerName, volunteerRole;
    int coolDown, maxDistance, distancePerStep, maxOrders;

    ss >> volunteerName >> volunteerRole >> coolDown;

    if (volunteerRole == "driver" || volunteerRole == "limited_driver") {
        // For drivers, parse additional parameters
        ss >> maxDistance >> distancePerStep;
    }

    // For both collector and driver, parse maxOrders if provided
    if (!(ss >> maxOrders)) {
        maxOrders = -1; // Unlimited if not provided
    }

    if (volunteerRole == "collector") {
        volunteers.push_back(new CollectorVolunteer(volunteerCounter, volunteerName, coolDown));
    } else if (volunteerRole == "limited_collector") {
        volunteers.push_back(new LimitedCollectorVolunteer(volunteerCounter, volunteerName, coolDown, maxOrders));
    } else if (volunteerRole == "driver") {
        volunteers.push_back(new DriverVolunteer(volunteerCounter, volunteerName, maxDistance, distancePerStep));
    } else if (volunteerRole == "limited_driver") {
        volunteers.push_back(new LimitedDriverVolunteer(volunteerCounter, volunteerName, maxDistance, distancePerStep, maxOrders));
    } else {
        throw std::invalid_argument("Invalid volunteer role");
    }
    volunteerCounter++; // Add one to the volunteer counter
}

WareHouse::WareHouse(const WareHouse &other)
    : isOpen(other.isOpen), customerCounter(other.customerCounter),
      volunteerCounter(other.volunteerCounter),orderCounter(other.orderCounter), defaultCustomer(nullptr),
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
    orderCounter = other.orderCounter;

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
        orderCounter = other.orderCounter;
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
        orderCounter = other.orderCounter;

        other.isOpen = false;
        other.customerCounter = 0;
        other.volunteerCounter = 0;
        other.orderCounter = 0;
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

    // TODO: Fix after everything compile
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
            int number_of_steps;
            ss >> number_of_steps;
            SimulateStep *step = new SimulateStep(number_of_steps);
            step->act(*this);
        }
        else if (actionName == "order")
        {
            // TODO
        }
        else if (actionName == "customer")
        {
            // TODO
        }
        else if (actionName == "orderStatus")
        {
            // TODO
        }
        else if (actionName == "customerStatus")
        {
            // TODO
        }
        else if (actionName == "volunteerStatus")
        {
            // TODO
        }
        else if (actionName == "log")
        {
            // TODO
            // PrintActionsLog *log = new PrintActionsLog();
            // log->act(*this);
        }
        else if (actionName == "close")
        {
            Close *close = new Close();
            close->act(*this);
        }
        else if (actionName == "backup")
        {
            // TODO
            // BackupWareHouse* backup = new BackupWareHouse();
            // backup->act(*this);
        }
        else if (actionName == "restore")
        {
            // TODO
            // RestoreWareHouse* restore = new RestoreWareHouse();
            // restore->act(*this);
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

// int WareHouse::getnewid(string counterType) const {
//     int id;
//     if (counterType == "customer"){
//         id = customerCounter;
//         customerCounter = customerCounter +1;
//     }
//     else if (counterType == "volunteer")
//     {
//         id = volunteerCounter;
//         volunteerCounter ++;
//     }
//     else
//     {
//         id = orderCounter;
//         orderCounter ++;
//     }
//     return id;
// };

bool WareHouse::isCustomerExsist(int customerId) const{
    if (customerId < this->customerCounter){
        return true;
    }
    return false;
};

