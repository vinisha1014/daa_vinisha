#include <iostream>
#include <vector>
#include <ctime>  // iise time measure kro
using namespace std;

// input aise lete hai
//     Enter number of vertices: 4
// Enter number of edges: 5
// Enter the edges (u v):
// 0 1
// 0 2
// 1 2
// 1 3
// 2 3
// Enter the number of colors: 3


//check karo kya safe hai color assign karna
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

//backtrack karoge 
bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size())
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // Backtrack
            color[v] = 0;
        }
    }
    return false;
}

//problem solve karne ka function
bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0); // sab 0

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist.\n";
        return false;
    }

    
    cout << "Color assignment to vertices:\n";
    for (int i = 0; i < color.size(); i++) {
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    }

    return true;
}

int main() {
    int V, E, m;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

   
    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // do baar add karo kyuki undirected graph hai

    cout << "Enter the number of colors: ";
    cin >> m;

  //time start kro
    clock_t start = clock();

   //function call karo
    graphColoring(graph, m);

    // End time measurement
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC; // in seconds
    cout << "Time taken by function: " << time_taken * 1000 << " milliseconds\n";

    return 0;

    
    }
}
