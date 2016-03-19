#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

bool wordPattern(string pattern, string str) {
    unordered_map<char, string> c_s;
    unordered_map<string, char> s_c;
    istringstream in(str);
    string word;
    for (auto &c : pattern) {
        in >> word;
        if (!c_s.count(c) && !s_c.count(word)) {
            c_s[c] = word;
            s_c[word] = c;
        }
        else if (c_s[c] != word || s_c[word] != c) return false;
    }
    return !(in >> word);
}

int main() {
    cout << wordPattern("aba", "foo 1 foo 3") << endl;
    return 0;
}
