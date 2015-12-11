#include <iostream>
using namespace std;

string countAndSay(int n) {
    string s("1");
    while (--n > 0) {
        int count = 1;
        string result("");
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) ++count;
            else {
                result += (string(1, '0'+count) + s[i-1]);
                count = 1;
            }
        }
        result += (string(1, '0'+count) + s[s.size()-1]);
        s = result;
    }
    return s;
}

int main() {
    cout << countAndSay(4) << endl;
    return 0;
}
