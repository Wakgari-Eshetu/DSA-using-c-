#include <iostream>
#include <queue>
using namespace std;

#define V 11   // Number of vertices

// BFS using adjacency matrix
bool hasPath_BFS(int adj[V][V], int start, int dest) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == dest)
            return true;  

        for (int i = 0; i < V; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return false;  
}


// DFS using adjacency matrix
bool hasPath_DFS(int adj[V][V], int v, int dest) {
    bool visited[V] = {false};
    if (v == dest)
        return true;

    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            if (hasPath_DFS(adj, i, dest))
                return true;
        }
    }
    return false;
}


int main() {
    string country[11] = {"Addis Ababa","Adama","hawassa","arbaminch","diredawa","jijiga","harar","debrebrehan","bahrdar","jimma","nekemte"};
    int adj[V][V] = {
        {0,1,0,0,0,0,0,1,0,1,0},
        {0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,0,0}
    };

    int src = 0;
    int dest = 3;

    if (hasPath_BFS(adj, src, dest))
        cout << "Path exists from " 
        << country[src] << " to " 
        << country[dest]<<endl;

    else
        cout << "Path doesnot exists from " 
            << country[src] << " to " 
            << country[dest]<<endl;

    

    if (hasPath_DFS(adj, src, dest))
        cout << "Path exists from " 
            << country[src] << " to " 
            << country[dest]<<endl;
    else
        cout << "Path doesnot exists from " 
        << country[src] << " to " 
        << country[dest]<<endl;

    return 0;
}
