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
        WareHouse(WareHouse&& other) noexcept;
        WareHouse &operator=(const WareHouse &other);
        WareHouse &operator=(WareHouse&& other) noexcept;
        ~WareHouse();

        void start();
        void addOrder(Order* order);
        void addAction(BaseAction* action);
        Customer &getCustomer(int customerId) const;
        Volunteer &getVolunteer(int volunteerId) const;
        Order &getOrder(int orderId) const;
        Order* getOrderPointer(int orderId) const; // Return the pointer of an order
        bool isOrderInPending(Order *targetOrder) const; // Return rather the given object is in the wareHouse pndingOrders vector
        const vector<BaseAction*> &getActions() const;
        void close();
        void open();
        const vector<Volunteer*> &getVolunteers() const;
        const vector<Order*> getPendingOrders() const;
        vector<Order*> getFinishCollectOrders() const; // Return volunteers from type collector that finis all steps
        void removeLimitedVolunteersReachingMax(); // Remove if reaching max and has no active action
        void removeFromList(Order* order, string listName);
        int getNewId(string counterType); // Return the relevant id by counter
        void addCustomer(Customer* customer);
        void addVolunteer(Volunteer* volunteer);
        Customer &getDefaultCustomer() const;
        Volunteer &getDefaultVolunteer() const;
        Order &getDefaultOrder() const;
        vector<Order*> getOrders() const; //return a vector of all orders
        

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
        Customer *defaultCustomer; // Default null customer
        Volunteer *defaultVolunteer; // Default null volunteer
        Order *defaultOrder; // Default null order

};