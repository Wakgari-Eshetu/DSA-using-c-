#include <iostream>
#include <queue>
using namespace std;

#define V 5   // Number of vertices

// BFS using adjacency matrix
void BFS_Matrix(int adj[V][V], int start) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < V; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// DFS using adjacency matrix
void DFS_Matrix(int adj[V][V], int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < V; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS_Matrix(adj, i, visited);
        }
    }
}

int main() {
    int adj[V][V] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,0},
        {0,0,1,0,0}
    };

    cout << "BFS (Matrix): ";
    BFS_Matrix(adj, 0);

    bool visited[V] = {false};
    cout << "\nDFS (Matrix): ";
    DFS_Matrix(adj, 0, visited);

    return 0;
}
