#include <bits/stdc++.h>
using namespace std;
#define le8 1e18

// Bellman-Ford Algorithm
// Time Complexity: O(V*E)
// Space Complexity: O(V)

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
        vector<int> dist(V, le8);
        dist[S] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != le8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];m
            int wt = it[2];
            if (dist[u] != le8 && dist[u] + wt < dist[v]) {
                return {-1}; // Negative weight cycle detected
            }
        }

        return dist;
    }
}; // ✅ Added semicolon here
