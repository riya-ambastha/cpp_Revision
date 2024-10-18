#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) return result;

         
        std::vector<std::string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        std::string combination;
        backtrack(result, mapping, combination, digits, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, const std::vector<std::string>& mapping,
                   std::string& combination, const std::string& digits, int index) {
        
        if (index == digits.size()) {
            result.push_back(combination);
            return;
        }

        
        int digit = digits[index] - '0';  
        const std::string& letters = mapping[digit];
 
        for (char letter : letters) {
            combination.push_back(letter);  
            backtrack(result, mapping, combination, digits, index + 1); 
            combination.pop_back();  
        }
    }
};

int main() {
    Solution solution;
    std::string digits;

    std::cout << "Enter the digits (2-9): ";
    std::cin >> digits;

    std::vector<std::string> combinations = solution.letterCombinations(digits);

    std::cout << "Possible letter combinations are: " << std::endl;
    for (const std::string& combination : combinations) {
        std::cout << combination << " ";
    }
    std::cout << std::endl;

    return 0;
}

