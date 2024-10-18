#include <iostream>
#include <climits> 
#include <cctype>  

int myAtoi(std::string s) {
    int i = 0, n = s.size();
    long result = 0;
    int sign = 1;
 
    while (i < n && isspace(s[i])) {
        i++;
    }

 
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');

       
        if (sign == 1 && result > INT_MAX) {
            return INT_MAX;  
        }
        if (sign == -1 && -result < INT_MIN) {
            return INT_MIN;  
        }
        i++;
    }

    return static_cast<int>(result * sign);
}

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);  

    int result = myAtoi(s);
    std::cout << "Converted integer: " << result << std::endl;

    return 0;
}