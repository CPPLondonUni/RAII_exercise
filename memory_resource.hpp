// Don't worry too much about what this code is doing!

#include <algorithm>
#include <iostream>

struct MemoryResource {
    int* ptr;
    int size;
};

inline MemoryResource acquire_resource(int size)
{
    auto p =  new int[size];
    int i = 0;
    std::generate(p, p + size, [&i] {
         ++i;
         return i * i;
    });
    return {p, size};
}

inline void release_resource(MemoryResource& resource)
{
    if (!resource.ptr) {
        std::cerr << "Error, attempting to release the same resource twice!\n";
    }
    delete[] resource.ptr;
    resource.ptr = nullptr;
}

inline MemoryResource copy_resource(const MemoryResource& resource)
{
    auto p = new int[resource.size];
    std::copy(resource.ptr, resource.ptr + resource.size, p);
    return {p, resource.size};
}

inline int access_resource(const MemoryResource& resource, int index)
{
    if (index >= 0 && index <= resource.size) {
        return resource.ptr[index];
    } else {
        throw std::out_of_range("access_resource called with out of range index");
    }
}
