#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger() {};

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// Solution 1 : top-down parser, recursive descent, trivial but elegant
class Solution_rd {
public:
    NestedInteger deserialize(string s) {
        int cur = 0;
        if (s[cur] == '[') {
            return parseList(s, cur);
        } else {
            return parseInteger(s, cur);
        }
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
