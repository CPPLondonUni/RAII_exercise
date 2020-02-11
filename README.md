
C++ London Uni RAII exercise
=============================

This repository contains a simple example of handling resources in C++.

The supplied `memory_resource.hpp` file provides the following functions:

* ```cpp
  MemoryResource acquire_resource(int size);
  ```
  
  Returns a `MemoryResource` object consisting of an array of `size` ints
  
* ```cpp
  void release_resource(MemoryResource& resource);
  ```
  
  Destroys a `MemoryResource` previously acquired by `acquire_resource()`
  
* ```cpp
  int access_resource(const MemoryResource& resource, int index);
  ```
  
  Returns the value at position `index` in the `MemoryResource` array
  
  
(Many C libraries provide APIs like this.)
  
The starter code in `main.cpp` uses the above functions to calculate the
sum of the values in a `MemoryResource` of a given size; however, if the
total is too small (less than 100), it returns zero instead.

Exercise 1
----------

Unfortunately, the `use_resource_example()` function in `main.cpp` has a bug!
Can you spot what it is?
  
This bug can be avoided by properly using RAII

  * Write a new class `ResourceHandle` which manages a `MemoryResource` by 
    automatically calling `acquire_resource()` when it is created, and
    `release_resource()` when it is destroyed
    
  * Add a member function to `ResourceHandle` which allows you to access
    the resource using `access_resource()`
    
  * Use this class to fix the bug in `use_resource_example()`
  
Exercise 2
----------

What happens when you create a *copy* of a `ResourceHandle` object? Why?

  * Update your `ResourceHandle` class to use the suppled function `copy_resource()`
    as appropriate to solve this problem