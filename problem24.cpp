#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2) {
    int m = num1.size();
    int n = num2.size();
     
    vector<int> result(m + n, 0);

  
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0'); 
            int sum = mul + result[i + j + 1];  

            result[i + j + 1] = sum % 10; 
            result[i + j] += sum / 10;    
        }
    }
 
    string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) {  
            product.push_back(num + '0');
        }
    }

    return product.empty() ? "0" : product;  
}

int main() {
    string num1 = "123";
    string num2 = "456";

    cout << "Product: " << multiply(num1, num2) << endl;

    return 0;
}
