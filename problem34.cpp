#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int numUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    unordered_set<int> occupied; // Stores occupied cells (guards and walls)
    unordered_set<int> guarded;  // Stores guarded cells

    // Lambda to convert 2D coordinates to 1D for hashable storage
    auto to1D = [&](int row, int col) {
        return row * n + col;
    };

    // Mark guards and walls as occupied
    for (const auto& g : guards) {
        occupied.insert(to1D(g[0], g[1]));
    }
    for (const auto& w : walls) {
        occupied.insert(to1D(w[0], w[1]));
    }

    // Direction vectors for North, East, South, West
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // Simulate guard vision
    for (const auto& g : guards) {
        int x = g[0], y = g[1];
        for (const auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            while (nx >= 0 && nx < m && ny >= 0 && ny < n && !occupied.count(to1D(nx, ny))) {
                guarded.insert(to1D(nx, ny));
                nx += dir.first;
                ny += dir.second;
            }
        }
    }

    // Count unguarded and unoccupied cells
    int unguardedCount = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int cell = to1D(i, j);
            if (!occupied.count(cell) && !guarded.count(cell)) {
                ++unguardedCount;
            }
        }
    }

    return unguardedCount;
}

int main() {
    int m = 4, n = 6;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};
    
    cout << "Unguarded cells: " << numUnguarded(m, n, guards, walls) << endl;

    return 0;
}
