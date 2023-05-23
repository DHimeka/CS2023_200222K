#include <iostream>
#include <climits>

#define V 6 //no of vertices

int minimumKey(int key[], bool mstSet[]) {
    int minVal = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < minVal) {
            minVal = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(int parent[], int graph[V][V]) {
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << std::endl;
    }
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minimumKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    //input the graph
    int graph[V][V] = { { 0, 4, 6, 0, 0, 0 },
                        { 4, 0, 6, 3, 4, 0 },
                        { 6, 6, 0, 1, 8, 0 },
                        { 0, 3, 1, 0, 2, 3 },
                        { 0, 4, 8, 2, 0, 7 },
                        { 0, 0, 0, 3, 7, 0 } };
    primMST(graph);

return 0;
}