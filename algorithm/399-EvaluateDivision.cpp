#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
#include <set> 
#include <queue> 
#include <unordered_map> 
using namespace std;

// Convert equations into edges with weight a/b of a graph
//      e.g. a / b = 2.0
//           a -> b, with value 2.0
//           b -> a, with value 1/2.0
// Then, for a qeury (x, y), we need to find a path from x to y, and time weights


// Solution 1 : trivial dfs, it can find path, and that's all.
// Furthermore, we can use other algorithms to find the shortest path, like BFS, Dijkstra, BellmanFord, FloydWarshall, etc.
class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_map<string, bool> visited;

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            graph[equations[i].first].push_back({equations[i].second, values[i]});
            graph[equations[i].second].push_back({equations[i].first, 1.0/values[i]});
        }

        vector<double> res;
        for (auto& q : queries) {
            double r = 1.0;
            visited.clear();
            if (!graph.count(q.first) || !graph.count(q.second) || !dfs(q.first, q.second, r)) res.push_back(-1.0);
            else res.push_back(r);
        }
        return res;
    }

    bool dfs(string start, string end, double& res) {
        if (start == end) return true;
        visited[start] = true;
        for (auto& p : graph[start]) {
            if (!visited[p.first]) {
                res *= p.second;
                if (dfs(p.first, end, res)) return true;
                res /= p.second;
            }
        }
        return false;
    }
};


// Solution 2 : uion-find
class Solution_2 {
private:
    struct Node {
        Node* parent;
        double value = 0.0;
        Node () : parent(this) {}
    };

    Node* findParent(Node* node) {
        if (node->parent != node)
            node->parent = findParent(node->parent);
        return node->parent;
    }

    void unionSet(Node* node1, Node* node2, double value, map<string, Node*>& m) {
        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
        double ratio = node2 -> value * value / node1 -> value;
        for (auto it = m.begin(); it != m.end(); it ++)
            if (findParent(it -> second) == parent1)
                it -> second -> value *= ratio;
        parent1 -> parent = parent2;
    }


public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, Node*> m;
        for (int i = 0; i < (int)equations.size(); i ++)
        {
            string s1 = equations[i].first, s2 = equations[i].second;
            if (m.count(s1) == 0 && m.count(s2) == 0)
            {
                m[s1] = new Node();
                m[s2] = new Node();
                m[s1] -> value = values[i];
                m[s2] -> value = 1;
                m[s1] -> parent = m[s2];
            } else if (m.count(s1) == 0) {
                m[s1] = new Node();
                m[s1] -> value = m[s2] -> value * values[i];
                m[s1] -> parent = m[s2];
            } else if (m.count(s2) == 0) {
                m[s2] = new Node();
                m[s2] -> value = m[s1] -> value / values[i];
                m[s2] -> parent = m[s1];
            } else unionSet(m[s1], m[s2], values[i], m);
        }

        vector<double> results;
        for (auto &q : queries) {
            string s1 = q.first, s2 = q.second;
            if (m.count(s1) == 0 || m.count(s2) == 0 || findParent(m[s1]) != findParent(m[s2]))
                results.push_back(-1.0);
            else 
                results.push_back(m[s1]->value / m[s2]->value);
        }
        return results;
    }
};


int main() {
    Solution s;
    vector<pair<string, string>> equations = {{"a","b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<pair<string, string>> queries = { { "a", "c" }, { "b", "a" }, { "a", "e" }, { "a", "a" }, { "x", "x" } };
    auto r = s.calcEquation(equations, values, queries);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
