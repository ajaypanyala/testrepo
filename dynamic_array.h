#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>
#include <cstring>

/**
 * A simple dynamic array implementation similar to std::vector
 * Demonstrates basic C++ concepts including templates, memory management,
 * and RAII (Resource Acquisition Is Initialization)
 */
template <typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[capacity];
        
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        
        delete[] data;
        data = new_data;
    }

public:
    // Constructor
    DynamicArray() : data(nullptr), capacity(0), size(0) {}

    // Constructor with initial capacity
    explicit DynamicArray(size_t initial_capacity) 
        : data(new T[initial_capacity]), capacity(initial_capacity), size(0) {}

    // Copy constructor
    DynamicArray(const DynamicArray& other) 
        : data(new T[other.capacity]), capacity(other.capacity), size(other.size) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // Add element to the end
    void push_back(const T& value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    // Remove element from the end
    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    // Access element at index
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Const version of operator[]
    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Get current size
    size_t get_size() const {
        return size;
    }

    // Get current capacity
    size_t get_capacity() const {
        return capacity;
    }

    // Check if array is empty
    bool empty() const {
        return size == 0;
    }

    // Clear all elements
    void clear() {
        size = 0;
    }

    // Reserve capacity
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }

    // Iterator support
    T* begin() { return data; }
    T* end() { return data + size; }
    const T* begin() const { return data; }
    const T* end() const { return data + size; }

    // Print array contents
    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

#endif // DYNAMIC_ARRAY_H
