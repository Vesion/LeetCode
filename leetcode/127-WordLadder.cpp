#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Outdated question: get the shortest path
// First use two-ends BFS to construct the graph, then use DFS to construct the path.
class OldSolution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &dict) {
        vector<vector<string> > paths;
        vector<string> path(1, beginWord);
        if (beginWord == endWord) {
            paths.push_back(path);
            return paths;
        }
        unordered_set<string> forward, backward;
        forward.insert(beginWord);
        backward.insert(endWord);
        unordered_map<string, vector<string> > tree;
        bool reversed = false; //make sure the tree generating direction is consistent, since we have to start from the smaller set to accelerate;
        if (buildTree(forward, backward, dict, tree, reversed))
            getPath(beginWord, endWord, tree, path, paths);
        return paths;
    }

private:
    bool buildTree(unordered_set<string> &forward, unordered_set<string> &backward, unordered_set<string> &dict, unordered_map<string, vector<string> > &tree, bool reversed) {
        if (forward.empty()) return false;
        if (forward.size() > backward.size())
            return buildTree(backward, forward, dict, tree, !reversed);
        for (auto &word: forward) dict.erase(word);
        for (auto &word: backward) dict.erase(word);
        unordered_set<string> nextLevel;
        bool done = false; //in case of invalid further searching;
        for (auto &it: forward) {
            string word = it;
            for (auto &c: word) {
                char c0 = c; //store the original;
                for (c = 'a'; c <= 'z'; ++c) {
                    if (c != c0) {
                        if (backward.count(word)) {
                            done = true;
                            !reversed ? tree[it].push_back(word) : tree[word].push_back(it); //keep the tree generation direction consistent;
                        }
                        else if (!done && dict.count(word)) {
                            nextLevel.insert(word);
                            !reversed ? tree[it].push_back(word) : tree[word].push_back(it);
                        }
                    }
                }
                c = c0; //restore the word;
            }
        }
        return done || buildTree(nextLevel, backward, dict, tree, reversed);
    }

    void getPath(string &beginWord, string &endWord, unordered_map<string, vector<string> > &tree, vector<string> &path, vector<vector<string> > &paths) {
        if (beginWord == endWord) {
            paths.push_back(path);
            return;
        }
        for (auto &it: tree[beginWord]) {
            path.push_back(it);
            getPath(it, endWord, tree, path, paths);
            path.pop_back();
        }
    }
};

// One-end BFS
class Solution_1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }
        int n = beginWord.size();
        // Small opt, only transform with chars occurred in dict.
        vector<unordered_set<char>> table(n);
        for (const string& word : dict) {
            for (int i = 0; i < n; ++i) table[i].insert(word[i]);
        }

        vector<string> state({beginWord});
        int step = 1;
        while (!state.empty()) {
            vector<string> new_state;
            ++step;
            for (string& word : state) {
                for (int i = 0; i < n; ++i) {
                    for (char c : table[i]) {
                        char oc = word[i];
                        if (oc == c) continue;
                        word[i] = c;
                        if (dict.count(word)) {
                            if (word == endWord) return step;
                            new_state.push_back(word);
                            dict.erase(word);
                        }
                        word[i] = oc;
                    }
                }
            }
            state.swap(new_state);
        }
        return 0;
    }
};

// Two-ends BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }
        int n = beginWord.size();

        unordered_set<string> forward({beginWord}), backward({endWord});
        int step = 1;
        while (!forward.empty() && !backward.empty()) {
            unordered_set<string>& state = forward.size() <= backward.size() ? forward : backward;
            unordered_set<string>& target = forward.size() > backward.size() ? forward : backward;
            ++step;
            unordered_set<string> new_state;
            for (const string& s : state) {
                string word = s;
                for (int i = 0; i < n; ++i) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        char oc = word[i];
                        if (oc == c) continue;
                        word[i] = c;
                        if (dict.count(word) || target.count(word)) {
                            if (target.count(word)) return step;
                            new_state.insert(word);
                            dict.erase(word);
                        }
                        word[i] = oc;
                    }
                }
            }
            state.swap(new_state);
        }
        return 0;
    }
};


int main() {
    Solution s;
    vector<string> list = {"hot","dot","dog","lot","log","cog"};
    cout << s.ladderLength("hit", "cog", list) << endl;
    return 0;
}

