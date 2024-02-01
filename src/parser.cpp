#include "Parser.h"
#include <sstream>
#include <stdexcept>

void Parser::parseConfigFile(WareHouse &warehouse, ifstream &configFile)
{
    string line;
    while (getline(configFile, line))
    {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        // Use a stringstream to parse the line
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "customer")
        {
            parseCustomer(warehouse, ss);
        }
        else if (command == "volunteer")
        {
            parseVolunteer(warehouse, ss);
        }
        else
        {
            throw std::invalid_argument("Unknown command");
        }
    }
};

void Parser::parseCustomer(WareHouse &warehouse, stringstream &ss)
{
    string customerName, customerTypeStr;
    int distance, maxOrders;

    ss >> customerName >> customerTypeStr >> distance >> maxOrders;

    if (customerTypeStr == "soldier")
    {
        warehouse.addCustomer(new SoldierCustomer(warehouse.getNewId("solider"), customerName, distance, maxOrders));
    }
    else if (customerTypeStr == "civilian")
    {
        warehouse.addCustomer(new CivilianCustomer(warehouse.getNewId("customer"), customerName, distance, maxOrders));
    }
    else
    {
        throw std::invalid_argument("Invalid customer type");
    }
};

void Parser::parseVolunteer(WareHouse &warehouse, stringstream &ss)
{
    string volunteerName, volunteerRole;
    int coolDown, maxDistance, distancePerStep, maxOrders;

    ss >> volunteerName >> volunteerRole;

    if (volunteerRole == "collector")
    {
        ss >> coolDown;
        warehouse.addVolunteer(new CollectorVolunteer(warehouse.getNewId("volunteer"), volunteerName, coolDown));
    }
    else if (volunteerRole == "limited_collector")
    {
        ss >> coolDown >> maxOrders;
        warehouse.addVolunteer(new LimitedCollectorVolunteer(warehouse.getNewId("volunteer"), volunteerName, coolDown, maxOrders));
    }
    else if (volunteerRole == "driver")
    {
        ss >> maxDistance >> distancePerStep;
        warehouse.addVolunteer(new DriverVolunteer(warehouse.getNewId("volunteer"), volunteerName, maxDistance, distancePerStep));
    }
    else if (volunteerRole == "limited_driver")
    {
        ss >> maxDistance >> distancePerStep >> maxOrders;
        warehouse.addVolunteer(new LimitedDriverVolunteer(warehouse.getNewId("volunteer"), volunteerName, maxDistance, distancePerStep, maxOrders));
    }
    else
    {
        throw std::invalid_argument("Invalid volunteer role");
    }
};
