 #include <iostream>
#include <vector>
using namespace std;

int findMinLastElement(int n, int x) {
    int current = x;
    for (int i = 1; i < n; ++i) {
        current++;
    }
    return current;
}

int main() {
    int n = 3, x = 4;
    cout << "Minimum possible value of nums[n-1]: " << findMinLastElement(n, x) << endl;
    
    n = 2, x = 7;
    cout << "Minimum possible value of nums[n-1]: " << findMinLastElement(n, x) << endl;

    return 0;
}
