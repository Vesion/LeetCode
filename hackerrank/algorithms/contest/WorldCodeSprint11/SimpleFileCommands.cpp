#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
#include <queue> 
#include <unordered_map> 
using namespace std;
using ll = long long;

using Q = priority_queue<int, vector<int>, greater<int>>;
unordered_map<string, Q> dict;

int create_f(string& file) {
    if (!dict.count(file)) {
        dict[file].push(1);
        return 0;
    } else {
        auto& pq = dict[file];
        int t = pq.top(); pq.pop();
        if (pq.empty()) pq.push(t+1);
        return t;
    }
}

void delete_f(string& file) {
    if (file.back() == ')') {
        int f = file.find("(");
        string sv = file.substr(f+1, file.size()-f-2);
        int ver = stoi(sv);
        dict[file.substr(0, f)].push(ver);
    } else dict[file].push(0);
}

void print(string& file) {
    Q c = dict[file];
    while (!c.empty()) { cout << c.top() << " " ; c.pop();} cout << endl;
}

int main() {
    int q; cin >> q;
    string cmd, file;
    while (q--) {
        cin >> cmd >> file;
        if (cmd[0] == 'c') {
            int ver = create_f(file);
            cout << "+ " << file << (ver ? "("+to_string(ver)+")" : "") << endl;
        } else if (cmd[0] == 'd') {
            delete_f(file);
            cout << "- " << file << endl;
        } else {
            string to; cin >> to;
            delete_f(file);
            int ver = create_f(to);
            cout << "r " << file << " -> ";
            cout << to << (ver ? "("+to_string(ver)+")" : "") << endl;
        }
    }
    return 0;
}
