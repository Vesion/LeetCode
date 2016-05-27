#include <iostream>
#include <vector>
using namespace std;

string reverseVowels(string s) {
    int l = s.size();
    if (l <= 1) return s;
    string vowels = "aeiouAEIOU";
    for (int i = 0, j = l-1; i < j; ) {
        while (vowels.find(s[i]) == string::npos && i < j) ++i;
        while (vowels.find(s[j]) == string::npos && i < j) --j;
        swap(s[i++], s[j--]);
    }
    return s;
}

int main() {
    cout << reverseVowels("leetcode") << endl;
    return 0;
}
