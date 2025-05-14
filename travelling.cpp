#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX
#include <ctime>    // For clock()
using namespace std;

//output aise lo
// Enter number of cities: 4
// Enter the distance matrix:
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0

int tspNearestNeighbour(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    int totalCost = 0;
    int currentCity = start;

    visited[currentCity] = true;
    cout << "Path: " << currentCity;

    for (int count = 1; count < n; count++) {
        int nextCity = -1;
        int minDist = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[currentCity][j] < minDist) {
                minDist = graph[currentCity][j];
                nextCity = j;
            }
        }

        if (nextCity == -1) break; 

        visited[nextCity] = true;
        totalCost += minDist;
        currentCity = nextCity;
        cout << " -> " << currentCity;
    }

    
    totalCost += graph[currentCity][start];
    cout << " -> " << start << endl;

    return totalCost;
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

   
    clock_t start = clock();

    int startCity = 0; // You can allow user to choose
    int cost = tspNearestNeighbour(graph, startCity);

    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Total cost of tour (approximate): " << cost << endl;
    cout << "Time taken: " << timeTaken * 1000 << " milliseconds" << endl;

    return 0;
}
