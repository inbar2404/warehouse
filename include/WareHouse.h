#pragma once
#include <string>
#include <vector>
using namespace std;

#include "Order.h"
#include "Customer.h"
#include "Volunteer.h"
#include "Action.h"

class BaseAction;
class Volunteer;
class Order;

// Warehouse responsible for Volunteers, Customers Actions, and Orders.

class WareHouse {

    public:
        WareHouse(const string &configFilePath);
        
        // Rule of 5 functions
        WareHouse(const WareHouse &other);
        WareHouse(WareHouse&& other);
        WareHouse &operator=(const WareHouse &other);
        WareHouse &operator=(WareHouse&& other);
        ~WareHouse();

        void start();
        void addOrder(Order* order);
        void addAction(BaseAction* action);
        Customer &getCustomer(int customerId) const;
        Volunteer &getVolunteer(int volunteerId) const;
        Order &getOrder(int orderId) const;
        Order* getOrderPointer(int orderId) const; // Return the pointer of an order
        const vector<BaseAction*> &getActions() const;
        void close();
        void open();
        const vector<Volunteer*> &getVolunteers() const;
        const vector<Order*> &getPendingOrders() const;
        vector<Order*> getFinishCollectOrders() const; // Return volunteers from type collector that finis all steps
        void removeLimitedVolunteersReachingMax(); // Remove if reaching max and has no active action
        void removeFromList(Order* order, string listName);
        void parseVolunteer(stringstream& ss);
        void parseConfigFile(ifstream& configFile);
        void parseCustomer(stringstream& ss);
        int getNewId(string counterType); // Return the relevant id by counter
        void addCustomer(Customer* customer);
        bool isCustomerExist(int customerId);
        // void printAction() const;
        Customer *defaultCustomer; // Default null customer
        Volunteer *defaultVolunteer; // Default null volunteer
        Order *defaultOrder; // Default null order

    private:
        bool isOpen;
        vector<BaseAction*> actionsLog;
        vector<Volunteer*> volunteers;
        vector<Order*> pendingOrders;
        vector<Order*> inProcessOrders;
        vector<Order*> completedOrders;
        vector<Customer*> customers;
        int customerCounter; // For assigning unique customer IDs
        int volunteerCounter; // For assigning unique volunteer IDs
        int orderCounter; // For assigning unique volunteer IDs
};