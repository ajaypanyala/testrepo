#include "StringUtils.h"
#include "MathUtils.h"
#include <iostream>
#include <vector>

using namespace Utils;

void demonstrateStringUtils() {
    std::cout << "=== String Utilities ===" << std::endl;
    std::string sample = "Hello World";
    std::cout << "Original: " << sample << std::endl;
    std::cout << "Uppercase: " << StringUtils::toUpper(sample) << std::endl;
    std::cout << "Lowercase: " << StringUtils::toLower(sample) << std::endl;
    std::cout << "Reversed: " << StringUtils::reverse(sample) << std::endl;
    
    std::string csv = "apple,banana,cherry";
    std::vector<std::string> fruits = StringUtils::split(csv, ',');
    std::cout << "\nSplit '" << csv << "':" << std::endl;
    for (const auto& fruit : fruits) std::cout << "  - " << fruit << std::endl;
    std::cout << "Joined: " << StringUtils::join(fruits, " | ") << std::endl;
}

void demonstrateMathUtils() {
    std::cout << "\n=== Math Utilities ===" << std::endl;
    std::cout << "Factorial of 5: " << MathUtils::factorial(5) << std::endl;
    
    std::cout << "Primes 0-10: ";
    for (int i = 0; i <= 10; ++i) {
        if (MathUtils::isPrime(i)) std::cout << i << " ";
    }
    std::cout << std::endl;
    
    std::cout << "GCD(48,18): " << MathUtils::gcd(48, 18) << std::endl;
    std::cout << "2^10: " << MathUtils::power(2.0, 10) << std::endl;
    
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3, 7};
    std::cout << "\nMax: " << MathUtils::max(numbers) 
              << ", Min: " << MathUtils::min(numbers)
              << ", Avg: " << MathUtils::average(numbers) << std::endl;
}

int main() {
    std::cout << "C++ Utilities Demo\n==================\n" << std::endl;
    try {
        demonstrateStringUtils();
        demonstrateMathUtils();
        std::cout << "\n=== Completed! ===" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
