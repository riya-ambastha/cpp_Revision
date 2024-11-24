#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maximizeMatrixSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int totalSum = 0;
    int minAbsValue = INT_MAX;
    int negativeCount = 0;

    // Traverse the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            totalSum += abs(matrix[i][j]);
            if (matrix[i][j] < 0) {
                negativeCount++;
            }
            minAbsValue = min(minAbsValue, abs(matrix[i][j]));
        }
    }

    // If there are an odd number of negative values, subtract twice the smallest absolute value
    if (negativeCount % 2 != 0) {
        totalSum -= 2 * minAbsValue;
    }

    return totalSum;
}

int main() {
    vector<vector<int>> matrix1 = {{1, -1}, {-1, 1}};
    cout << "Maximum Sum: " << maximizeMatrixSum(matrix1) << endl;

    vector<vector<int>> matrix2 = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    cout << "Maximum Sum: " << maximizeMatrixSum(matrix2) << endl;

    return 0;
}

