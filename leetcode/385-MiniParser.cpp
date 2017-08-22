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
        int i = 0;
        if (s[i] == '[') return parseList(s, i);
        else return parseInteger(s, i);
    }

    NestedInteger parseList(string& s, int& i) {
        NestedInteger res;
        ++i; // read '['
        while (i < (int)s.size()) {
            if (s[i] == '[') res.add(parseList(s, i));
            else if (s[i] == '-' || isdigit(s[i])) res.add(parseInteger(s, i));
            else if (s[i] == ',') ++i;
            else break;
        }
        ++i; // read ']'
        return res;
    }

    NestedInteger parseInteger(string& s, int& i) {
        int num = 0, sign = 1;
        if (s[i] == '-') { sign = -1; ++i; }
        while (i < (int)s.size() && isdigit(s[i])) num = num*10 + s[i++]-'0';
        return NestedInteger(sign * num);
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
