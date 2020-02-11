
#include "memory_resource.hpp"

#include <iostream>

int use_resource_example(int size)
{
    auto resource = acquire_resource(size);

    int total = 0;
    for (int i = 0; i < size; i++) {
        total += access_resource(resource, i);
    }

    if (total < 100) {
        std::cout << "total was too small\n";
        return 0;
    }

    release_resource(resource);
    return total;
}

int main()
{
    // Find the smallest size for which use_resource_example returns non-zero
    int size = 1;
    while (use_resource_example(size) == 0) {
        ++size;
    }

    std::cout << "Smallest size to give non-zero total is " << size << '\n';
}



