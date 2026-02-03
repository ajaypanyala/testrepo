# C++ Utilities Library

A simple C++ utility library demonstrating string and mathematical operations.

## Files

- **StringUtils.h** / **StringUtils.cpp**: String manipulation utilities
- **MathUtils.h** / **MathUtils.cpp**: Mathematical operation utilities  
- **main.cpp**: Demonstration program
- **Makefile**: Build system

## Features

### String Utilities
- Convert to uppercase/lowercase
- Trim whitespace
- Split and join strings
- Reverse strings
- Check prefix/suffix
- Count character occurrences

### Math Utilities
- Factorial calculation
- Prime number checking
- GCD and LCM
- Power calculation
- Vector operations (min, max, sum, average)
- Even/odd checking

## Building

```bash
# Compile
make

# Run
make run

# Clean
make clean
```

## Usage Example

```cpp
#include "StringUtils.h"
#include "MathUtils.h"

// String operations
std::string upper = StringUtils::toUpper("hello");
std::vector<std::string> parts = StringUtils::split("a,b,c", ',');

// Math operations
long long fact = MathUtils::factorial(5);
bool prime = MathUtils::isPrime(7);
int gcd = MathUtils::gcd(48, 18);
```

## Requirements

- C++11 or later
- g++ compiler
