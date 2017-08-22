#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

string s;

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> s;
        if (next_permutation(s.begin(), s.end())) cout << s << endl;
        else cout << "no answer" << endl;
    }
    return 0;
}
