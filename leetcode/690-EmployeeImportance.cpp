#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    unordered_map<int, Employee*> c;

    int getImportance(vector<Employee*> employees, int id) {
        for (Employee* e : employees) c[e->id] = e;
        if (!c.count(id)) return 0;
        return dfs(c[id]);
    }

    int dfs(Employee* e) {
        int res = e->importance;
        for (int d : e->subordinates) {
            res += dfs(c[d]);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<Employee*> es = {new Employee({1, 2, {2}}), new Employee({2, 3, {}})};
    cout << s.getImportance(es, 1) << endl;
    return 0;
}
