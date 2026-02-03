#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>

namespace Utils {

class StringUtils {
public:
    // Convert string to uppercase
    static std::string toUpper(const std::string& str);
    
    // Convert string to lowercase
    static std::string toLower(const std::string& str);
    
    // Trim whitespace from both ends
    static std::string trim(const std::string& str);
    
    // Split string by delimiter
    static std::vector<std::string> split(const std::string& str, char delimiter);
    
    // Join vector of strings with delimiter
    static std::string join(const std::vector<std::string>& vec, const std::string& delimiter);
    
    // Check if string starts with prefix
    static bool startsWith(const std::string& str, const std::string& prefix);
    
    // Check if string ends with suffix
    static bool endsWith(const std::string& str, const std::string& suffix);
    
    // Reverse a string
    static std::string reverse(const std::string& str);
    
    // Count occurrences of a character
    static int countChar(const std::string& str, char c);
};

} // namespace Utils

#endif // STRINGUTILS_H
