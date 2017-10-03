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
  unordered_set<int> s;

  int getImportance(vector<Employee*> employees, int id) {
    if (s.count(id)) return 0;
    s.insert(id);
    int i = 0;
    for (int j = 0; j < (int)employees.size(); ++j) if (employees[j]->id == id) { i = j; break; }
    int res = employees[i]->importance;;
    for (int& sub : employees[i]->subordinates) {
      res += getImportance(employees, sub);
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
