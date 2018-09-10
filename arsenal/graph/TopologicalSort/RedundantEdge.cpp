#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <unordered_map> 
#include <stack> 
using namespace std;

// Problem: Given a graph with N nodes and N edges, remove a redundant edge to make it be a tree.


// Problem 1 : Undirected Graph
// Solution: Union Find
//
class Solution_U {
private:
  vector<int> root;
  int findRoot(int i) {
    if (i != root[i]) root[i] = findRoot(root[i]);
    return root[i];
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    root.resize(n+1);
    iota(root.begin(), root.end(), 0);
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      int ru = findRoot(u), rv = findRoot(v);
      if (ru == rv) return e;
      root[ru] = rv;
    }
    return {};
  }
};



// Problem 2 : Directed Graph
//
// Solution:
// We need to check 3 different cases:
//    1. No cycle, but there is one node has two parents, [[1,2], [2,3], [3,1]]
//    2. No duplicate parents, bu has cycle, [[1,2], [1,3], [2,3]]
//    3. Has cycle and duplicate parents, [[2,1], [3,1], [4,2], [1,4]]
// For case 3, we need to record the whole cycle, then check edges in reversed order to find the node which has the same child as the duplicated one we found.
//
// https://discuss.leetcode.com/topic/105087/share-my-solution-c
//
class Solution_D {
private:
  struct Node{
    vector<int> parents; //parent(s), at most one node has 2 parents in a graph
    vector<int> children; //children, can have many children
  };
  unordered_map<int,Node> getNode;
  unordered_map<int,unordered_map<int,int>> edgeOrder;

public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    //construct the graph
    int N = edges.size();
    for(int n = 1; n <= N; ++n) getNode[n] = Node();
    int node2parents = -1; // try to find the node has 2 parents
    for(int i = 0; i < N; ++i){
      int p = edges[i][0];
      int c = edges[i][1];
      edgeOrder[p][c] = i;
      getNode[p].children.push_back(c);
      getNode[c].parents.push_back(p);
      if(getNode[c].parents.size() == 2) node2parents = c;
    }

    //doing DFS to find the loop if loop exists
    vector<int> status(N+1,0); // status 0,1,2 ==> 0:unvisited, 1:visiting, 2:visited
    stack<int> loop;
    bool loopfound = false;
    for(int i = 1; i <= N; ++i){
      if(loopfound) break;
      if(status[i] == 0){ //DFS started with node i
        status[i] = 1;
        stack<int> stk({i});
        DFS(stk,status,loopfound,loop);
        status[i] = 2;
      }
    }

    if(!loopfound){ // Case 1
      int parent1 = getNode[node2parents].parents[0];
      int parent2 = getNode[node2parents].parents[1];
      return (edgeOrder[parent1][node2parents] > edgeOrder[parent2][node2parents]) ?
        vector<int>({parent1,node2parents}) : vector<int>({parent2,node2parents});
    }

    int last_occur_order = 0;
    vector<int> last_occur_edge;
    int begin = loop.top();
    while(!loop.empty()){
      int child = loop.top();
      loop.pop();
      int parent = loop.top();
      if(node2parents != -1 && child == node2parents) // Case 3
        return vector<int>({parent,child});
      int order = edgeOrder[parent][child];
      if(order > last_occur_order){
        last_occur_order = order;
        last_occur_edge = vector<int>({parent,child});
      }
      if(parent == begin) break; //loop ends
    }

    return last_occur_edge; // Case 2
  }

  void DFS(stack<int>& stk, vector<int>& status, bool& found, stack<int>& loop){
    for (int c : getNode[stk.top()].children){
      if (found) return;
      if (status[c] == 1) {
        stk.push(c);
        loop = stk;
        found = true;
        return;
      } else if(status[c] == 0) {
        stk.push(c);
        status[c] = 1;
        DFS(stk,status,found,loop);
        status[c] = 2;
        stk.pop();
      }
    }
  }
};


int main() {
  return 0;
}
