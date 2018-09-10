#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Bellman-Ford, O(VE)

const int MAX = 100;

struct Edge {
    int u, v;
    int weight;
} edges[MAX];

int N, M; // number of nodes and edges
int dist[MAX];

// Bellman-Ford, O(VE) time
// return false if there exists a negative cycle
bool BellmanFord(int s) {
    // init
    for (int i = 1; i <= N; ++i)
        dist[i] = INT_MAX;
    dist[s] = 0;

    // N-1 relaxations
    for (int i = 1; i <= N-1; ++i) {
        for (int j = 1; j <= M; ++j) {
            int u = edges[j].u, v = edges[j].v;
            if (dist[u] != INT_MAX && dist[v] > dist[u] + edges[j].weight)
                dist[v] = dist[u] + edges[j].weight;
        }
    }

    // check negative cycle
    for (int j = 1; j <= M; ++j)
        if (dist[edges[j].v] > dist[edges[j].u] + edges[j].weight)
            return false;
    return true;
}


int main() {
    return 0;
}
