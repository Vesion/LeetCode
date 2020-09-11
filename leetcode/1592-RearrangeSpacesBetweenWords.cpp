#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int s = 0;
        for (char c : text) if (c == ' ') ++s;
        istringstream ss(text);
        string word;
        vector<string> words;
        while (ss >> word) words.push_back(word);

        string res;
        int t1, t2;
        if (words.size() == 1) t1 = 0, t2 = s;
        else t1 = s / (words.size()-1), t2 = s % (words.size()-1);
        for (int i = 0; i < words.size(); ++i) {
            res += words[i];
            if (i != words.size()-1) res += string(t1, ' ');
        }
        res += string(t2, ' ');
        return res;
    }
};

int main() {
    return 0;
}
