
#include "memory_resource.hpp"

#include <iostream>

struct ResourceHandle {

    explicit ResourceHandle(int size)
        : res(acquire_resource(size))
    {}

    ~ResourceHandle()
    {
        release_resource(res);
    }

    int access(int idx) const { return access_resource(res, idx); }

private:
    MemoryResource res;
};

int use_resource_example(int size)
{
    auto resource = ResourceHandle(size);

    int total = 0;
    for (int i = 0; i < size; i++) {
        total += resource.access(i);
    }

    if (total < 100) {
        std::cout << "total was too small\n";
        return 0;
    }

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



