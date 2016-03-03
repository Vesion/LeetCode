#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Solution 1 : use array to store tokens, O(n) time, O(n) space
void reverseWords(string &s) {
    vector<string> words;
    int start = -1;
    int i;
    for (i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            if (start != -1) {
                words.push_back(s.substr(start, i-start));
                start = -1;
            }
            continue;
        }
        if (start == -1) start = i;
    }
    if (start != -1) words.push_back(s.substr(start, i-start+1));
    if (words.empty()) s = "";
    else {
        reverse(words.begin(), words.end());
        s = words[0];
        for (int i = 1; i < words.size(); ++i)
            s += (" " + words[i]);
    }
}


// Solution 2 : use stringstream, O(n) time, O(1) space, slower
void reverseWords_ss(string &s) {
    stringstream ss(s);
    string word = "";
    string result = "";
    while (ss >> word) {
        word += (" " + result);
        result = word;
    }
    s = result.substr(0, result.size()-1);
}

int main() {
    string s = "af  adfsdf ";
    //reverseWords(s);
    reverseWords_ss(s);
    cout << s << endl;
    return 0;
}
