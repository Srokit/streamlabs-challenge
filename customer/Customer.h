
#pragma once

#include <string>
#include <vector>

#include "Product.h"

class Customer {
public:
    Customer(std::string name_in): name(name_in) {}
    std::string get_name() const;
private:
    std::string name;
};