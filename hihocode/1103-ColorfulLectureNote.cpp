#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    string s; 
    int c[3] = {0, 0, 0}; // red, yellow, blue
    getline(cin, s);
    int n = s.size();
    int i = 0;
    stack<int> st;
    int counter = 0;
    while (i < n) {
        if (s[i] == '<') {
            ++i;
            if (s[i] == '/') {
                ++i;
                if (s[i] == 'r') c[0] += counter; 
                else if (s[i] == 'y') c[1] += counter; 
                else if (s[i] == 'b') c[2] += counter;
                counter = st.top();
                st.pop();
            } else {
                st.push(counter);
                counter = 0;
            }
            while (i < n && s[i] != '>') ++i;
        } 
        else if (s[i] >= 'a' && s[i] <= 'z') ++counter;
        ++i;
    }

    cout << c[0] << " " << c[1] << " " << c[2] << endl;
    return 0;
}
