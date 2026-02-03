#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <vector>

namespace Utils {

class MathUtils {
public:
    // Calculate factorial (valid for n <= 20 to avoid overflow)
    static long long factorial(int n);
    
    // Check if number is prime
    static bool isPrime(int n);
    
    // Calculate greatest common divisor
    static int gcd(int a, int b);
    
    // Calculate least common multiple
    static int lcm(int a, int b);
    
    // Calculate power
    static double power(double base, int exponent);
    
    // Find maximum in vector
    static int max(const std::vector<int>& vec);
    
    // Find minimum in vector
    static int min(const std::vector<int>& vec);
    
    // Calculate sum of vector
    static long long sum(const std::vector<int>& vec);
    
    // Calculate average of vector
    static double average(const std::vector<int>& vec);
    
    // Check if number is even
    static bool isEven(int n);
    
    // Check if number is odd
    static bool isOdd(int n);
};

} // namespace Utils

#endif // MATHUTILS_H
