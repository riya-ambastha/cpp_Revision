#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1)); // Initialize memoization table
        int maxMoves = 0;

        // Helper function for DFS
        function<int(int, int)> dfs = [&](int row, int col) {
            // If we've already calculated this cell, return the stored result
            if (memo[row][col] != -1) return memo[row][col];
            
            int moves = 0;
            // Explore the three possible moves: top-right, right, and bottom-right
            for (int dRow : {-1, 0, 1}) {
                int newRow = row + dRow;
                int newCol = col + 1;
                if (newRow >= 0 && newRow < m && newCol < n && grid[newRow][newCol] > grid[row][col]) {
                    moves = max(moves, 1 + dfs(newRow, newCol));
                }
            }
            // Store the result in memo and return
            return memo[row][col] = moves;
        };

        // Start DFS from every cell in the first column and update maxMoves
        for (int row = 0; row < m; ++row) {
            maxMoves = max(maxMoves, dfs(row, 0));
        }

        return maxMoves;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    cout << "Output: " << solution.maxMoves(grid1) << endl;  // Expected output: 3

    vector<vector<int>> grid2 = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};
    cout << "Output: " << solution.maxMoves(grid2) << endl;  // Expected output: 0

    return 0;
}
