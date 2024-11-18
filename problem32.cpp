#include <iostream>
#include <vector>
using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> result(n, 0);

    if (k == 0) {
        return result; // Replace all elements with 0 if k == 0
    }

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        if (k > 0) {
            // Sum of the next k numbers
            for (int j = 1; j <= k; ++j) {
                sum += code[(i + j) % n]; // Wrap around using modulo
            }
        } else {
            // Sum of the previous |k| numbers
            for (int j = 1; j <= abs(k); ++j) {
                sum += code[(i - j + n) % n]; // Wrap around using modulo
            }
        }
        result[i] = sum;
    }

    return result;
}

int main() {
    // Example 1
    vector<int> code1 = {5, 7, 1, 4};
    int k1 = 3;
    vector<int> result1 = decrypt(code1, k1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> code2 = {1, 2, 3, 4};
    int k2 = 0;
    vector<int> result2 = decrypt(code2, k2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Example 3
    vector<int> code3 = {2, 4, 9, 3};
    int k3 = -2;
    vector<int> result3 = decrypt(code3, k3);
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

