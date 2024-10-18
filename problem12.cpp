#include <iostream>
#include <vector>
#include <string>

bool isMatch(const std::string& s, const std::string& p) {
    int m = s.length();
    int n = p.length();
    
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

 
    dp[0][0] = true;

     
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];   
        }
    }

   
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                
                dp[i][j] = dp[i][j - 2];

                 
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }
 
    return dp[m][n];
}

int main() {
    std::string s, p;
    std::cout << "Enter the string: ";
    std::cin >> s;
    std::cout << "Enter the pattern: ";
    std::cin >> p;

    if (isMatch(s, p)) {
        std::cout << "The string matches the pattern." << std::endl;
    } else {
        std::cout << "The string does not match the pattern." << std::endl;
    }

    return 0;
}
