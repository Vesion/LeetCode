#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const string t = "marshtomp";
const string r = "fjxmlhx";

int main() {
    string s;
    while (getline(cin, s)) {
        string cs = s;
        for (char& c : cs) if (isalpha(c)) c = tolower(c);
        string res;
        size_t i = cs.find(t, 0), j = 0;
        while (i != string::npos) {
            res += s.substr(j, i-j) + r;
            j = i+t.size();
            i = cs.find(t, j);
        }
        res += s.substr(j);
        cout << res << endl;
    }
    return 0;
}
