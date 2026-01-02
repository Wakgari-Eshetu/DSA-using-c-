#include <iostream>
#include <queue>
using namespace std;

#define V 11

// Node of linked list
struct Node {
    int vertex;
    Node* next;
};

struct Graph {
    Node* adj[V];   
};

Node* createNode(int v) {
    Node* newNode = new Node();
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

bool hasPath_BFS(Graph* graph, int start, int dest) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == dest)
            return true;

        Node* temp = graph->adj[v];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
            temp = temp->next;
        }
    }
    return false;
}

bool hasPath_DFS(Graph* graph, int v, int dest, bool visited[]) {
    if (v == dest)
        return true;

    visited[v] = true;

    Node* temp = graph->adj[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            if (hasPath_DFS(graph, adjVertex, dest, visited))
                return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Graph graph;
    string country[11] = {"Addis Ababa","Adama","hawassa","arbaminch","diredawa","jijiga","harar","debrebrehan","bahrdar","jimma","nekemte"};
    

    for (int i = 0; i < V; i++)
        graph.adj[i] = NULL;

   
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 7);
    addEdge(&graph, 0, 9);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 4, 5);
    addEdge(&graph, 4, 6);
    addEdge(&graph, 7, 0);
    addEdge(&graph, 7, 8);
    addEdge(&graph, 8, 7);
    addEdge(&graph, 9, 10);

    int src = 0, dest = 3;

    if (hasPath_BFS(&graph, src, dest))
        cout << "Path exists from " << country[src] << " to " << country[dest];
    else
        cout << "No path from " << counrty[src] << " to " << country[dest];

    bool visited[V] = {false};
    if (hasPath_DFS(&graph, src, dest, visited))
        cout << "Path exists from " << country[src] << " to " << country[dest] << " (DFS)" << endl;
    else
        cout << "No path from " << country[src] << " to " << country[dest] << " (DFS)" << endl;

    return 0;
}
