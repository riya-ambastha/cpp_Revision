#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
 
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
 
    dp[0][0] = true;
 
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

   
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                 
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
          
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s = "aa";
    string p = "*";

    if (isMatch(s, p)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
