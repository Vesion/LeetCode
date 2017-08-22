#include <iostream>
#include <cstring>
#include <cctype> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        string t;
        int i = 0;
        while (s[i] == ' ') ++i;
        bool begin = true;
        while (i < (int)s.size()) {
            if (isalpha(s[i])) {
                if (begin) {
                    t.push_back(toupper(s[i++]));
                    begin = false;
                }
                else t.push_back(tolower(s[i++]));
            }
            else if ((s[i]) == ' ') {
                while ((s[i]) == ' ') ++i;
                if (isalpha(s[i])) t.push_back(' ');
            } 
            else {
                if (s[i] == '.') begin = true;
                t.push_back(s[i++]);
            }
        }
        cout << t << endl;
    }
    
    return 0;
}
