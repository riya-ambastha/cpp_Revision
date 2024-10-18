#include <iostream>

bool isPalindrome(int x) {
     
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;

    int reversedNum = 0;
 
    while (x > reversedNum) {
        int pop = x % 10;   
        reversedNum = reversedNum * 10 + pop;  
        x /= 10;   
    }

     
    return x == reversedNum || x == reversedNum / 10;
}

int main() {
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (isPalindrome(x)) {
        std::cout << x << " is a palindrome." << std::endl;
    } else {
        std::cout << x << " is not a palindrome." << std::endl;
    }

    return 0;
}
