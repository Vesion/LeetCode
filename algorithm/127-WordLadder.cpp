#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

// a classical bfs problem

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    if (wordList.empty()) return 0;

    queue<pair<string, int>> q; // use queue to maintain bfs nodes, a node is a pair consisting of string and its level(or steps)
    q.push(make_pair(beginWord, 1)); // beginWord is our starting node
    wordList.insert(endWord); // put endWord in wordlist to return result

    while (!q.empty()) {
        auto node = q.front(); // get current node
        q.pop();
        string word = node.first;

        if (word == endWord) return node.second; // if we find endword, return its level immediately, bfs assure the shortest steps

        for (int i = 0; i < word.size(); ++i) { // try to transform every char
            string temp = word;
            for (char c = 'a'; c <= 'z'; ++c) { // try 26 letters
                temp[i] = c;
                if (wordList.find(temp) != wordList.end() && temp != word) { // if we get a new word, and it is in wordlist
                    q.push(make_pair(temp, node.second+1)); // add the new word to next level
                    wordList.erase(temp); // delete the word in wordlist, for faster finding next time
                }
            }
        }

    }
    return 0;
}

int main() {
    unordered_set<string> wordList {"hot","dot","dog","lot","log"};
    cout << ladderLength("hit", "cog", wordList) << endl;
    return 0;
}
