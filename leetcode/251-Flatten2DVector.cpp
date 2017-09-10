#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Vector2D {
public:
    using it = vector<int>::iterator;
    vector<pair<it,it>> its;
    vector<pair<it,it>>::iterator row;
    
    Vector2D(vector<vector<int>>& vec2d) {
        if (!vec2d.empty()) {
            for (auto& v : vec2d) its.push_back({v.begin(), v.end()});
        }
        row = its.begin();
    }

    int next() {
        if (hasNext()) return *row->first++;
        return 0;
    }

    bool hasNext() {
        while (row != its.end()) {
            if (row->first != row->second) return true;
            ++row;
        }
        return false;
    }
};


int main() {
    return 0;
}
