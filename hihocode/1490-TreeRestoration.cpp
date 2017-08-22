#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 105;
int N, M, K;

int num_level[MAXN]; // number of nodes in each level
int level[MAXN][MAXN]; // nodes of each level
int dist[MAXN][MAXN]; // distance between two nodes
bool is_leaf[MAXN]; // check if it is a leaf node
int leaf[MAXN]; // leaf nodes
int parent[MAXN]; // result we print out

int main() {
    cin >> N >> M >> K; 
    for (int i = 0; i < M; ++i) cin >> num_level[i];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < num_level[i]; ++j) cin >> level[i][j];
    }
    for (int i = 0; i < K; ++i) {
        cin >> leaf[i];
        is_leaf[leaf[i]] = true;
    }
    for (int i = 0; i < K; ++i) 
        for (int j = 0; j < K; ++j) cin >> dist[leaf[i]][leaf[j]];

    // travel from bottom to up
    for (int l = M-1; l > 0; --l) {
        int node_id = 0, lastparent_id = 0;
        while (node_id < num_level[l]) {
            // skip all leaf nodes, the first non-leaf node is a parent node
            int parent_id = lastparent_id;
            while (parent_id < num_level[l-1] && is_leaf[level[l-1][parent_id]]) ++parent_id;
            parent[level[l][node_id]] = level[l-1][parent_id];

            // after setting current node's parent
            // look at nodes afterwards, if distance between it and current node is 2, they must be brothers
            int brother_num = 0;
            for (int brother_id = node_id+1; brother_id < num_level[l]; ++brother_id) {
                if (dist[level[l][node_id]][level[l][brother_id]] == 2) {
                    parent[level[l][brother_id]] = level[l-1][parent_id];
                    for (int i = 1; i <= N; ++i) dist[i][level[l][brother_id]] = dist[level[l][brother_id]][i] = 0; // don't forget to remove nodes have been processed
                    ++brother_num;
                    is_leaf[level[l][brother_id]] = false;
                }
            }

            // regard the parent node as a new leaf node, update distance between other nodes and it
            for (int i = 1; i <= N; ++i) {
                if (dist[level[l][node_id]][i] > 0) {
                    dist[level[l-1][parent_id]][i] = dist[i][level[l-1][parent_id]] = dist[level[l][node_id]][i]-1;
                }
            }

            // don't forget to remove current node
            for (int i = 1; i <= N; ++i) dist[i][level[l][node_id]] = dist[level[l][node_id]][i] = 0;
            is_leaf[level[l][node_id]] = false;

            node_id += brother_num+1;
            lastparent_id = parent_id+1;
        }
    }


    for (int i = 1; i <= N; ++i) cout << parent[i] << " ";
    cout << endl;

    return 0;
}
