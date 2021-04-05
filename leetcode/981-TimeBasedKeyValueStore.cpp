#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class TimeMap {
public:
    unordered_map<string, map<int, string>> m;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto it = m.find(key);
        if (it == m.end()) return "";
        const auto& t = it->second;
        auto tit = t.upper_bound(timestamp);
        if (tit == t.begin()) return "";
        return prev(tit)->second;
    }
};

int main() {

}