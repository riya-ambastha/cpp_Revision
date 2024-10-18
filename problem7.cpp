#include <iostream>
#include <climits>  
int reverse(int x) {
    int reversedNum = 0;

    while (x != 0) {
        int pop = x % 10;   
        x /= 10;            

 
        if (reversedNum > INT_MAX / 10 || (reversedNum == INT_MAX / 10 && pop > 7)) {
            return 0;   
        }
        if (reversedNum < INT_MIN / 10 || (reversedNum == INT_MIN / 10 && pop < -8)) {
            return 0;  
        }

        reversedNum = reversedNum * 10 + pop;  
    }

    return reversedNum;
}

int main() {
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    int result = reverse(x);
    std::cout << "Reversed number: " << result << std::endl;

    return 0;
}
