#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool isSubsequence(string& w, string& s) {
    int n = w.size();
    int i = 0;
    for (char& c : s) {
        if (i == n) break;
        if (c == w[i]) ++i;
    }
    return i == n;
}

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; ++i) cin >> words[i];
    string s;
    cin >> s;

    sort(words.begin(), words.end(), [](const string& w1, const string& w2) { return w1.size() > w2.size(); });
    for (string& w : words) {
        if (isSubsequence(w, s)) {
            cout << w.size() << endl;
            break;
        }
    }
    return 0;
}
