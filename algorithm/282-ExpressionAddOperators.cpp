#include <iostream>
#include <vector>
#include <string>
using namespace std;



// Solution 1 : dfs, brute-force, 324ms

// path : expression generated so far
//  pos : current visiting position of num
//  cur : cumulative value so far, finally use it to compare with target
//   pv : previous operand value
//   op : previous operator used
void dfs(vector<string>& result, string& num, int target, string path, int pos, long cur, long prev) {
    if (pos == num.size()) {
        if (cur == target) result.push_back(path);
        return;
    }
    for (int i = pos; i < num.size(); ++i) {
        if (num[pos] == '0' && i > pos) return; // meet prefix 0, prune
        string t = num.substr(pos, i-pos+1);
        long now = stol(t);
        if (pos == 0)
            dfs(result, num, target, path+t, i+1, now, now);
        else {
            dfs(result, num, target, path+'+'+t, i+1, cur+now, now);
            dfs(result, num, target, path+'-'+t, i+1, cur-now, -now);
            dfs(result, num, target, path+'*'+t, i+1, cur-prev+prev*now, prev*now); // well played
        }
    }
}

vector<string> addOperators(string num, int target) {
    if (num.empty()) return {};
    vector<string> result;
    dfs(result, num, target, "", 0, 0, 0);
    return result;
}

int main() {
    auto r = addOperators("3456237490", 9191);
    for (auto s : r) cout << s << endl;
    return 0;
}
