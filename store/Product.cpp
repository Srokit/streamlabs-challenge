
#include "Product.h"

#include <sstream>

#include "nlohmann/json.hpp"

// TODO: Fill out

ProductFamily to_family_enum(std::string family_str) {
    if (family_str == "keyboard") 
        return ProductFamily::KEYBOARD;
    if (family_str == "mouse")
        return ProductFamily::MOUSE;
    if (family_str == "webcam")
        return ProductFamily::WEBCAM;
    else // (family_str == "microphone")
        return ProductFamily::MICROPHONE;
}

Product::Product(nlohmann::json json_obj) {
    id = json_obj["id"];
    family = to_family_enum(json_obj["family"]);
    name = json_obj["name"];
    amountAvailable = json_obj["amountAvailable"];
    amountSold = json_obj["amountSold"];
    price = json_obj["price"];   
}

std::string Product::to_string() {
    std::stringstream ss;
    ss << "id: " << id << "\n";
    ss << "name: " << name << "\n";
    return ss.str();
}