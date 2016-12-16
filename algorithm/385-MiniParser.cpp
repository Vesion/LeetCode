#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class NestedInteger {
public:
    NestedInteger() {};
    NestedInteger(int value);
    bool isInteger() const;
    int getInteger() const;
    void setInteger(int value);
    void add(const NestedInteger &ni);
    const vector<NestedInteger> &getList() const;
};

// Solution 1 : top-down parser, recursive descent, trivial but elegant
class Solution {
public:
    NestedInteger deserialize(string s) {
        int cur = 0;
        if (s[cur] == '[') return parseList(s, cur); 
        else return parseInteger(s, cur);
    }

    NestedInteger parseList(string& s, int &cur) { // one pair of [], one object
        ++cur; // eat '['
        NestedInteger result;
        while (cur < (int)s.size()) {
            if (s[cur] == '[') {
                result.add(parseList(s, cur));
            } else if (s[cur] == ',') {
                ++cur;
            } else if (s[cur] == ']') {
                break;
            } else {
                result.add(parseInteger(s, cur));
            }
        }
        ++cur; // eat ']'
        return result;
    }

    NestedInteger parseInteger(string &s, int &cur) {
        int num = 0, sign = 1;
        while (cur < (int)s.size()) {
            if (s[cur] == '-') {
                sign = -1;
                ++cur;
            } else if (s[cur] >= '0' && s[cur] <= '9') {
                num = num * 10 + (s[cur] - '0');
                ++cur;
            } else break;
        }
        return NestedInteger(num * sign);
    }
};


// Solution 2 : top-down, using istringstream
class Solution_iss {
public:
    NestedInteger deserialize(string s) {
        istringstream in(s);
        return deserialize(in);
    }

    NestedInteger deserialize(istringstream &in) {
        int num;
        if (in >> num) return NestedInteger(num);

        NestedInteger result;
        in.clear();
        in.get();
        while (in.peek() != ']') {
            result.add(deserialize(in));
            if (in.peek() == ',')
                in.get();
        }
        in.get();
        return result;
    }
};


int main() {
    return 0;
}
