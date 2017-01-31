#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Vector2D {
private:
    using vit = vector<int>::iterator;
    vector<pair<vit, vit>> its;
    vector<pair<vit, vit>>::iterator cur;

public:
    Vector2D(vector<vector<int>>& vec2d) {
        if (!vec2d.empty()) {
            for (auto& vec : vec2d) its.push_back({vec.begin(), vec.end()});
            cur = its.begin();
        }
    }

    int next() {
        if (hasNext()) return *(cur->first++);
        return 0;
    }

    bool hasNext() {
        if (its.empty()) return false;
        while (cur != its.end()) {
            if (cur->first == cur->second) ++cur;
            else return true;
        }
        return false;
    }
};


int main() {
    return 0;
}
