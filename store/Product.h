
#pragma once

#include <string>

#include "nlohmann/json.hpp"

enum class ProductFamily {
    KEYBOARD,
    MOUSE,
    WEBCAM,
    MICROPHONE
};

class Product {
public:
    Product(nlohmann::json);

    std::string to_string();
private:
    std::string id;
    ProductFamily family;
    std::string name;
    int amountAvailable;
    int amountSold;
    int price;
};