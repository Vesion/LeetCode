#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> board(128, 0);
        string r1 = "qwertyuiopQWERTYUIOP";
        string r2 = "asdfghjklASDFGHJKL";
        string r3 = "zxcvbnmZXCVBNM";
        for (char& c : r1) board[c] = 1;
        for (char& c : r2) board[c] = 2;
        for (char& c : r3) board[c] = 3;
        
        vector<string> res;
        for (string& word : words) {
            bool f = true;
            for (int i = 0; i < (int)word.size(); ++i) {
                if (board[word[i]] == 0 || (i > 0 && board[word[i]] != board[word[i-1]])) { f = false; break; }
            }
            if (f) res.push_back(word);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<string> words = { "Hello","Alaska","Dad","Peace" };
    auto r = s.findWords(words);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
