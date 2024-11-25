#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int slidingPuzzle(vector<vector<int>>& board) {
    // Target solved state
    string target = "123450";
    // Flatten the 2x3 board into a string
    string start = "";
    for (const auto& row : board) {
        for (int num : row) {
            start += to_string(num);
        }
    }
    
    // Possible moves based on the 0 position (index in the string)
    vector<vector<int>> moves = {
        {1, 3},       // 0 can move to 1 or 3
        {0, 2, 4},    // 1 can move to 0, 2, or 4
        {1, 5},       // 2 can move to 1 or 5
        {0, 4},       // 3 can move to 0 or 4
        {1, 3, 5},    // 4 can move to 1, 3, or 5
        {2, 4}        // 5 can move to 2 or 4
    };
    
    // BFS setup
    queue<pair<string, int>> q; // {current state, moves}
    unordered_set<string> visited; // Visited states
    q.push({start, 0});
    visited.insert(start);
    
    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();
        
        // Check if solved
        if (current == target) {
            return steps;
        }
        
        // Find position of '0'
        int zeroPos = current.find('0');
        
        // Explore all valid moves
        for (int nextPos : moves[zeroPos]) {
            string nextState = current;
            swap(nextState[zeroPos], nextState[nextPos]);
            
            // Process unvisited states
            if (!visited.count(nextState)) {
                q.push({nextState, steps + 1});
                visited.insert(nextState);
            }
        }
    }
    
    return -1; // No solution
}

int main() {
    vector<vector<int>> board1 = {{1, 2, 3}, {4, 0, 5}};
    vector<vector<int>> board2 = {{1, 2, 3}, {5, 4, 0}};
    vector<vector<int>> board3 = {{4, 1, 2}, {5, 0, 3}};
    
    cout << "Example 1: " << slidingPuzzle(board1) << endl;
    cout << "Example 2: " << slidingPuzzle(board2) << endl;
    cout << "Example 3: " << slidingPuzzle(board3) << endl;

    return 0;
}
