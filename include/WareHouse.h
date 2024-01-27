#pragma once
#include <string>
#include <vector>
using namespace std;

#include "Order.h"
#include "Customer.h"
#include "Volunteer.h"

class BaseAction;
class Volunteer;

// Warehouse responsible for Volunteers, Customers Actions, and Orders.

class WareHouse {

    public:
        WareHouse(const string &configFilePath);
        void start();
        void addOrder(Order* order);
        void addAction(BaseAction* action);
        Customer &getCustomer(int customerId) const;
        Volunteer &getVolunteer(int volunteerId) const;
        Order &getOrder(int orderId) const;
        const vector<BaseAction*> &getActions() const;
        void close();
        void open();
        const vector<Order*> &getPendingOrders() const;
        vector<Order*> &getFinishCollectOrders() const; // Return volunteers from type collector that finis all steps
        vector<Volunteer*> &getvolunteersInAction() const; // Return volunteers have order in process
        void removeOrder(Order* order) const;
        void removeLimitedVolunteersReachingMax() const; // Remove if reaching max and has no active action
        CollectorVolunteer getAvailableCollector() const; // Return available collector to take an order
        DriverVolunteer getAvailableDriver() const; // Return available driver to take an order

    private:
        bool isOpen;
        vector<BaseAction*> actionsLog;
        vector<Volunteer*> volunteers;
        vector<Order*> pendingOrders;
        vector<Order*> inProcessOrders;
        vector<Order*> completedOrders;
        vector<Customer*> customers;
        int customerCounter; //For assigning unique customer IDs
        int volunteerCounter; //For assigning unique volunteer IDs
        Customer *defaultCustomer; // default null customer
        Volunteer *defaultVolunteer; // default null volunteer
        Order *defaultOrder; // default null order
};