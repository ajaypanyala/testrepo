#include "MathUtils.h"
#include <algorithm>
#include <stdexcept>
#include <cmath>

namespace Utils {

long long MathUtils::factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial is not defined for negative numbers");
    }
    if (n > 20) {
        throw std::overflow_error("Factorial overflow: n > 20 exceeds long long range");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

bool MathUtils::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int MathUtils::gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int MathUtils::lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    int gcd_val = gcd(a, b);
    return std::abs(a / gcd_val) * std::abs(b);
}

double MathUtils::power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    }
    if (exponent < 0) {
        return 1.0 / power(base, -exponent);
    }
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int MathUtils::max(const std::vector<int>& vec) {
    if (vec.empty()) {
        throw std::invalid_argument("Cannot find max of empty vector");
    }
    return *std::max_element(vec.begin(), vec.end());
}

int MathUtils::min(const std::vector<int>& vec) {
    if (vec.empty()) {
        throw std::invalid_argument("Cannot find min of empty vector");
    }
    return *std::min_element(vec.begin(), vec.end());
}

long long MathUtils::sum(const std::vector<int>& vec) {
    long long result = 0;
    for (int num : vec) {
        result += num;
    }
    return result;
}

double MathUtils::average(const std::vector<int>& vec) {
    if (vec.empty()) {
        throw std::invalid_argument("Cannot calculate average of empty vector");
    }
    return static_cast<double>(sum(vec)) / vec.size();
}

bool MathUtils::isEven(int n) {
    return n % 2 == 0;
}

bool MathUtils::isOdd(int n) {
    return n % 2 != 0;
}

} // namespace Utils
