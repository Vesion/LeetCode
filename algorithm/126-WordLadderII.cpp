#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <deque>
using namespace std;

// similiar to 127, but this problem require all shortest pathes
// so firstly bfs to construct ajacent table, then dfs to get all pathes

// TLE in leetcode, haven't find better solution
vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    vector<vector<string>> result;
    deque<vector<string>> q; // all pathes with same number of words
    bool found = false;

    q.push_back(vector<string>{beginWord});
    wordList.insert(endWord);
    
    while (!found && !q.empty()) {
        vector<vector<string>> tq {q.begin(), q.end()};
        q.clear();
        vector<string> eraser;

        for (auto &v : tq) { // for every path
            string word = v.back();
            if (word == endWord) { // if the last word is equal to endWord
                found = true; // we found it
                result.push_back(v); // add this path to result
                continue;
            }

            for (int i = 0; i < word.size(); ++i) { // modify the last word character by character
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == word[i]) continue;
                    string temp = word;
                    temp[i] = c; // get a new word
                    if (wordList.find(temp) != wordList.end()) { // if the new word is in wordList
                        v.push_back(temp); // append the new word to this path
                        q.push_back(v); // add this path to q
                        v.pop_back(); // recover path
                        eraser.push_back(temp); // record the new word in wordList
                    }
                }
            }
        }

        for (auto &w : eraser) // after traversing all pathes, erase those words have been found, in case of backforward path
            wordList.erase(w);
    }
    return result;
}

int main() {
    unordered_set<string> wordList = {"hot","dot","dog","lot","log"};
    auto result = findLadders("hit", "cog", wordList);
    for (auto i : result) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
