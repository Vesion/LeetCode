#include <iostream>
#include <string>
using namespace std;

// Solution 1 : use hash table to store number of appearence of each character
bool isAnagram_map(string s, string t) {
    int n = s.size(), m = t.size();
    if (n == m && n == 0) return true;
    if (n != m) return false;
    int table[26] = {0};
    for (auto &c : s) ++table[c-'a'];
    for (auto &c : t) {
        int k = c - 'a';
        if (!table[k]) return false;
        --table[k];
    }
    return true;
}


// Solution 2 : sort
bool isAnagram_sort(string s, string t) {
    sort(s.begin(), s.end());    
    sort(t.begin(), t.end());    
    return s == t;
}

int main() {
    cout << isAnagram_map("anagram", "nagaram") << endl;
    cout << isAnagram_sort("anagram", "nagaram") << endl;
    return 0;
}
