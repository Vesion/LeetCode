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
    unordered_map<int, const Employee*> m;

    int dfs(int id) {
        const Employee* e = m[id];
        int sum = e->importance;
        for (int sub_id : e->subordinates) {
            sum += dfs(sub_id);
        }
        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for (const Employee* e : employees) m[e->id] = e;
        return dfs(id);
    }
};


int main() {
    Solution s;
    vector<Employee*> es = {new Employee({1, 2, {2}}), new Employee({2, 3, {}})};
    cout << s.getImportance(es, 1) << endl;
    return 0;
}
