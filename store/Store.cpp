
#include "Store.h"

#include <fstream>
#include <sstream>

#include "nlohmann/json.hpp"

Store::Store() {
    // Load in data from json
    const char* json_file = "./assets/store.json";

    std::ifstream json_file_obj;
    json_file_obj.open(json_file);
    // TODO: Check for file can't open
    
    std::stringstream ss;
    ss << json_file_obj.rdbuf();
    std::string json_str(ss.str());

    auto json_dict = nlohmann::json::parse(json_file);
    auto prods_json_array = json_dict["products"];
    for (auto &prod_json_dict : prods_json_array) {
        products.push_back(Product(prod_json_dict));
    }
}

std::string Store::get_products_debug() {
    std::stringstream ss;
    ss << "Products:";
    for (auto &p : products) {
        ss << "\t" << p.to_string() << "\n";
    }
    return ss.str();
}


// Dynamic lib entry points for main executable
extern "C" Store* create_store() {
    return new Store;
}

extern "C" void destroy_store(Store* store) {
    delete store;
}