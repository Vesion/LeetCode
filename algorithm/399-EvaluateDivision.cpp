#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
#include <set> 
#include <queue> 
using namespace std;

// Solution 1 : graph + bfs/dfs
class Solution_bfs {
public:
    map<string, set<string>> graph;
    map<pair<string, string>, double> weights;
    map<string, bool> visited;

    void make(vector<pair<string, string>>& equations, vector<double>& values) {
        for (int i = 0; i < (int)equations.size(); ++i) {
            auto p = equations[i];
            graph[p.first].insert(p.second);
            graph[p.second].insert(p.first);
            weights[p] = values[i];
            weights[{p.second, p.first}] = 1.0 / values[i];
        }
    }

    double bfs(string& s1, string& s2) {
        queue<pair<string, double>> q;
        q.push({s1, 1.0});
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            string s = p.first;
            double r = p.second;

            if (visited[s]) continue;
            visited[s] = true;

            if (graph.find(s) == graph.end()) break;
            for (auto &nbr : graph[s]) {
                double newr = r * weights[{s, nbr}];
                if (nbr == s2) return newr;
                q.push({nbr, newr});
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        make(equations, values);
        int n = queries.size();
        vector<double> results(n);
        for (int i = 0; i < n; ++i) {
            for (auto &v : visited) v.second = false;
            auto p = queries[i];
            results[i] = bfs(p.first, p.second);
        }
        return results;
    }
};


// Solution 2 : uion-find set
class Solution {
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
