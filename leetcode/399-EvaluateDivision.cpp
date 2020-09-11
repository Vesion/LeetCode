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

    vector<double> calcEquation(vector<vector<string>> equations,
                                vector<double>& values,
                                vector<vector<string>> queries) {
        for (int i = 0; i < (int)equations.size(); ++i) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }

        unordered_map<string, bool> visited;
        vector<double> res;
        for (auto& q : queries) {
            double r = 1.0;
            visited.clear();
            if (!graph.count(q[0]) ||
                !graph.count(q[1]) ||
                !dfs(visited, q[0], q[1], r)) res.push_back(-1.0);
            else res.push_back(r);
        }
        return res;
    }

    bool dfs(unordered_map<string, bool>& visited, string start, string end, double& res) {
        if (start == end) return true;
        visited[start] = true;
        for (auto& p : graph[start]) {
            if (!visited[p.first]) {
                res *= p.second;
                if (dfs(visited, p.first, end, res)) return true;
                res /= p.second;
            }
        }
        return false;
    }
};


// Solution 2 : Build a fully-connected graph, every query takes O(1) time
class Solution_2 {
public:
    vector<double> calcEquation(vector<vector<string>> equations,
                                vector<double>& values,
                                vector<vector<string>> queries) {
        unordered_map<string, unordered_map<string, double>> quot;
        for (int i = 0; i < (int)equations.size(); ++i) {
            quot[equations[i][0]][equations[i][0]] = 1.0;
            quot[equations[i][1]][equations[i][1]] = 1.0;
            quot[equations[i][0]][equations[i][1]] = values[i];
            quot[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        for (auto& k : quot) {
            for (auto& i : quot[k.first]) {
                for (auto& j : quot[k.first]) {
                    quot[i.first][j.first] = quot[i.first][k.first] * quot[k.first][j.first];
                }
            }
        }
        vector<double> res;
        for (auto& q : queries) {
            if (!quot.count(q[0]) || !quot[q[0]].count(q[1])) res.push_back(-1.0);
            else res.push_back(quot[q[0]][q[1]]);
        }
        return res;
    }
};


// Solution 3 : uion-find
class Solution_3 {
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
    vector<double> calcEquation(vector<vector<string>> equations,
                                vector<double>& values,
                                vector<vector<string>> queries) {
        map<string, Node*> m;
        for (int i = 0; i < (int)equations.size(); i ++)
        {
            string s1 = equations[i][0], s2 = equations[i][1];
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
            string s1 = q[0], s2 = q[1];
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
