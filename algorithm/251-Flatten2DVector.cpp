#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Vector2D {
private:
    vector<vector<int>>::iterator begin, end;
    vector<int>::iterator it;

public:
    Vector2D(vector<vector<int>>& vec2d) {
        begin = vec2d.begin(), end = vec2d.end();
        if (begin != end) it = begin->begin();
    }

    int next() {
        if (hasNext()) return *it++;
        return 0; // invalid code
    }

    bool hasNext() {
        while (begin != end && it == begin->end()) { // skip all empty vector
            ++begin;
            it = begin->begin();
        }
        return begin != end;
    }
};


int main() {
    vector<vector<int>> v = {{}, {}, {5,6}, {}, {}, {1}};
    Vector2D v2(v);
    cout << v2.next() << endl;
    cout << v2.next() << endl;
    cout << v2.next() << endl;
    cout << v2.hasNext() << endl;
    cout << v2.next() << endl;
    return 0;
}
