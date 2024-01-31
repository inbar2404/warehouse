#pragma once
#include <fstream>
#include <sstream>
#include "WareHouse.h"

class WareHouse;

class Parser {
public:
    static void parseConfigFile(WareHouse& warehouse, ifstream& configFile);
    static void parseCustomer(WareHouse& warehouse, stringstream& ss);
    static void parseVolunteer(WareHouse& warehouse, stringstream& ss);
};
