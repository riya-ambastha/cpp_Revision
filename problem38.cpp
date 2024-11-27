#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the shortest path from city 0 to city n-1 using Dijkstra's algorithm
int findShortestPath(int n, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n, INT_MAX); // Distance from source to each node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap
    
    dist[0] = 0; // Distance to source is 0
    pq.emplace(0, 0); // Push source with distance 0
    
    while (!pq.empty()) {
        auto [currentDist, currentNode] = pq.top();
        pq.pop();
        
        if (currentDist > dist[currentNode]) continue; // Skip outdated distances
        
        for (auto& [neighbor, weight] : graph[currentNode]) {
            if (dist[currentNode] + weight < dist[neighbor]) {
                dist[neighbor] = dist[currentNode] + weight;
                pq.emplace(dist[neighbor], neighbor);
            }
        }
    }
    
    return dist[n - 1];
}

vector<int> shortestPathLength(int n, vector<vector<int>>& queries) {
    vector<vector<pair<int, int>>> graph(n); // Adjacency list (node, weight)
    
    // Initially, build the graph with the default roads
    for (int i = 0; i < n - 1; ++i) {
        graph[i].emplace_back(i + 1, 1); // Road from i to i+1 with weight 1
    }
    
    vector<int> answer;
    
    // Process each query
    for (auto& query : queries) {
        int u = query[0], v = query[1];
        graph[u].emplace_back(v, 1); // Add the new road
        
        // Compute the shortest path from city 0 to city n-1
        answer.push_back(findShortestPath(n, graph));
    }
    
    return answer;
}

int main() {
    int n1 = 5;
    vector<vector<int>> queries1 = {{2, 4}, {0, 2}, {0, 4}};
    vector<int> result1 = shortestPathLength(n1, queries1);
    for (int r : result1) cout << r << " ";
    cout << endl;

    int n2 = 4;
    vector<vector<int>> queries2 = {{0, 3}, {0, 2}};
    vector<int> result2 = shortestPathLength(n2, queries2);
    for (int r : result2) cout << r << " ";
    cout << endl;

    return 0;
}
