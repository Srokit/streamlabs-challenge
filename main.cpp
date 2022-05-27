
#include <dlfcn.h>
#include <iostream>
#include <thread>

#include "Store.h"

const int NUM_TO_BUY = 100;

// As long as n < 100
int get_random_0_to_n(int n) {
    return static_cast<int>(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)) * 100.0) % n;
}

std::string choose_random_str(const std::vector<std::string>& strs) {
    std::cout << get_random_0_to_n(strs.size()) << std::endl;
    return strs[get_random_0_to_n(strs.size())];
}

void buy_randomly(Store* store, Customer *customer) {
    std::vector<std::string> product_ids = store->get_all_product_ids();
    std::cout << product_ids.size() << std::endl;
    for (int i = 0; i < NUM_TO_BUY; i++) {
        std::cout << "buy" << std::endl;
        std::string prod_id = choose_random_str(product_ids);
        bool can_afford = store->purchase_by_id(prod_id, customer->get_name());
    }
}

void test() {
}

int main() {

    std::string id_prefix = "11bf5b37-e0b8-42e0-8dcf-dc8c4aefc00";

    void* handle = dlopen("libstream_labs_store.dylib", RTLD_LAZY);

    Store* (*create)();
    void (*destroy)(Store*);

    create = (Store* (*)())dlsym(handle, "create_store");
    destroy = (void (*)(Store*))dlsym(handle, "destroy_store");

    Store* store = (Store*)create();
    
    Customer customer1("Customer1");
    Customer customer2("Customer2");
    std::thread customer_1_thread(buy_randomly, store, &customer1);
    std::thread customer_2_thread(buy_randomly, store, &customer2);

    customer_1_thread.join();
    customer_2_thread.join();

    destroy( store );

    return 0;
}