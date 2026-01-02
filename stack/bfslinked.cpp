#include <iostream>
#include <list>
#include <queue>
using namespace std;

// DFS function
void DFS(int node, list<int> adj[], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

// BFS function
void BFS(int start, int V, list<int> adj[]) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;
    list<int> adj[V];   // adjacency list using linked list

    // Adding edges (undirected graph)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    bool visited[V] = {false};

    cout << "DFS Traversal: ";
    DFS(0, adj, visited);
    cout << endl;

    BFS(0, V, adj);

    return 0;
}
