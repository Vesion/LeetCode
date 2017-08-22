#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

int main() {
    int n; cin >> n; 
    unordered_map<string, int> indegrees;
    for (int i = 0; i < n; ++i) {
        string from, to;
        cin >> from >> to;
        --indegrees[from];
        ++indegrees[to];
    }
    string start, finish;
    for (auto& p : indegrees) {
        if (p.second < 0) start = p.first;
        else if (p.second > 0) finish = p.first;
    }
    cout << start << " " << finish << endl;
    return 0;
}
