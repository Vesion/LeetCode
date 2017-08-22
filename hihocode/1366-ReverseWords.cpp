#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

int main() {
    int N; cin >> N;    
    unordered_set<string> s;
    string w;
    int res = 0;
    while (N--) {
        cin >> w;
        if (s.count(w)) ++res;
        else {
            reverse(w.begin(), w.end());
            s.insert(w);
        }
    }
    cout << res << endl;
    return 0;
}
