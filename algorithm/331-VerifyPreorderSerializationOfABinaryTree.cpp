#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;


// Solution 1 : stack, learn to use getline(istream& is, string& str, char delim)
bool isValidSerialization_stack(string preorder) {
    if (preorder.empty()) return false;
    istringstream in(preorder);
    string token;
    stack<string> s;
    while (getline(in, token, ',')) {
        while (token == "#" && !s.empty() && s.top() == token) {
            s.pop();
            if (s.empty()) return false;
            s.pop();
        }
        s.push(token);
    }
    return s.size()==1 && s.top()=="#";
}


// Solution 2 : indegrees and outdegrees, skillful
// https://leetcode.com/discuss/83824/7-lines-easy-java-solution
bool isValidSerialization(string preorder) {
    if (preorder.empty()) return false;
    int diff = 1; // outdegrees - indegrees
    istringstream in(preorder);
    string token;
    while (getline(in, token, ',')) {
        if (--diff < 0) return false; // when a new node comes, it provides 1 indgree
        if (token != "#") diff += 2; // a non-null node provides 2 outdegrees
    }
    return diff == 0;
}


// Solution 3 : regex, more skillful
// here given in JAVA
//
//public boolean isValidSerialization(String preorder) {
    //String s = preorder.replaceAll("\\d+,#,#", "#");
    //return s.equals("#") || !s.equals(preorder) && isValidSerialization(s);
//}

int main() {
    cout << isValidSerialization_stack("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    return 0;
}
