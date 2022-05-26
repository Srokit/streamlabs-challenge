
#include <dlfcn.h>
#include <iostream>

#include "Store.h"

int main() {

    void* handle = dlopen("libstream_labs_store.so", RTLD_LAZY);

    Store* (*create)();
    void (*destroy)(Store*);

    create = (Store* (*)())dlsym(handle, "create_store");
    destroy = (void (*)(Store*))dlsym(handle, "destroy_store");

    Store* store = (Store*)create();
    std::cout << store->get_products_debug() << std::endl;
    destroy( store );

    return 0;
}