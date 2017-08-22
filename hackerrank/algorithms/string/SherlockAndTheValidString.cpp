#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 1e5+5;
char s[MAXN];
int a[26];

bool solve() {
    int n = strlen(s);
    for (int i = 0; i < n; ++i) a[s[i]-'a']++;
    vector<int> s;
    for (int i = 0; i < 26; ++i) if (a[i]) s.push_back(a[i]);
    sort(s.begin(), s.end());
    int m = s.size();
    return (s[0] == s[m-1]) || (s[1] == s[m-1] && s[0] == 1) || (s[0] == s[m-2] && s[0]+1 == s[m-1]);
}

int main() {
    scanf("%s", s); 
    bool r = solve();
    if (r) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
