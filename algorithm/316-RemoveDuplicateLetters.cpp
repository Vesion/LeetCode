#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

// a really hard greedy problem


// Solution 1 : stack, O(n) time
string removeDuplicateLetters_stack(string s) {
    if (s.empty()) return s;
    stack<char> stk;
    bool visited[26] = {};
    int count[26] = {0};
    for (char & c : s) ++count[c-'a'];
    for (int i = 0; i < s.size(); --count[s[i]-'a'], ++i) {
        if (visited[s[i]-'a'] || (!stk.empty() && stk.top() == s[i])) continue;
        while (!stk.empty() && stk.top() > s[i] && count[stk.top()-'a']) {
            visited[stk.top()-'a'] = false;
            stk.pop();
        }
        stk.push(s[i]);
        visited[s[i]-'a'] = true;
    }
    string result;
    while (!stk.empty()) result += stk.top(), stk.pop();
    reverse(result.begin(), result.end());
    return result;
}


// Solution 1 v2 : no stack, the most understandable solution! O(n) time, 4ms
string removeDuplicateLetters(string s) {
    int count[256] = {0};
    for (char & c : s) ++count[c];
    string result; // the whitespace is sentinel
    bool inresult[256] = {false};
    for (char & c : s) {
        --count[c];
        if (inresult[c]) continue;
        while (!result.empty() && c < result.back() && count[result.back()]) {
            inresult[result.back()] = false;
            result.pop_back();
        }
        result += c;
        inresult[c] = true;
    }
    return result;
}

int main() {
    cout << removeDuplicateLetters_stack("baa") << endl;
    cout << removeDuplicateLetters("baa") << endl;
    return 0;
}
