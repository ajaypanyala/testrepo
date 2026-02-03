#include <iostream>
#include <string>
#include "dynamic_array.h"

void test_basic_operations() {
    std::cout << "\n=== Basic Operations ===" << std::endl;
    DynamicArray<int> arr;
    for (int i = 1; i <= 5; ++i) arr.push_back(i * 10);
    std::cout << "Size: " << arr.get_size() << ", Capacity: " << arr.get_capacity() << std::endl;
    std::cout << "Contents: "; arr.print();
    std::cout << "Element at index 2: " << arr[2] << std::endl;
    arr.pop_back();
    std::cout << "After pop_back: "; arr.print();
}

void test_copy_operations() {
    std::cout << "\n=== Copy Operations ===" << std::endl;
    DynamicArray<int> arr1;
    arr1.push_back(1); arr1.push_back(2); arr1.push_back(3);
    std::cout << "Original: "; arr1.print();
    DynamicArray<int> arr2(arr1);
    std::cout << "Copied: "; arr2.print();
    arr1.push_back(4);
    std::cout << "After modifying original: "; arr1.print();
    std::cout << "Copy unchanged: "; arr2.print();
}

void test_string_array() {
    std::cout << "\n=== String Array ===" << std::endl;
    DynamicArray<std::string> names;
    names.push_back("Alice"); names.push_back("Bob");
    names.push_back("Charlie"); names.push_back("Diana");
    std::cout << "Names: "; names.print();
}

void test_iterators() {
    std::cout << "\n=== Iterators ===" << std::endl;
    DynamicArray<int> arr;
    for (int i = 1; i <= 5; ++i) arr.push_back(i * i);
    std::cout << "Using range-based for: ";
    for (const auto& val : arr) std::cout << val << " ";
    std::cout << std::endl;
}

void test_exception_handling() {
    std::cout << "\n=== Exception Handling ===" << std::endl;
    DynamicArray<int> arr;
    arr.push_back(10); arr.push_back(20);
    try {
        int val = arr[5];
        std::cout << "Value: " << val << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void demonstrate_practical_usage() {
    std::cout << "\n=== Grade Management ===" << std::endl;
    DynamicArray<double> grades;
    grades.push_back(85.5); grades.push_back(92.0);
    grades.push_back(78.5); grades.push_back(95.0); grades.push_back(88.0);
    std::cout << "Grades: "; grades.print();
    double sum = 0.0;
    for (size_t i = 0; i < grades.get_size(); ++i) sum += grades[i];
    std::cout << "Average: " << sum / grades.get_size() << std::endl;
}

int main() {
    std::cout << "Dynamic Array Implementation Demo" << std::endl;
    std::cout << "==================================" << std::endl;
    try {
        test_basic_operations();
        test_copy_operations();
        test_string_array();
        test_iterators();
        test_exception_handling();
        demonstrate_practical_usage();
        std::cout << "\nAll tests completed successfully!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
