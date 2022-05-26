
#pragma once

#include <string>
#include <vector>

#include "Product.h"

class Store {
    // TODO: Fill out
    public:
        Store();

        // DEBUG: Remove
        virtual std::string get_products_debug();
    private:
        std::vector<Product> products;
};