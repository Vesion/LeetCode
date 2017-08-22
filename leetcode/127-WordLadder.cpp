#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

// First use two-ends BFS to construct the graph, then use DFS to construct the path.
class Solution {
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


int main() {
    Solution s;
    unordered_set<string> l = {"ted", "rex", "tad", "tex"};
    auto r = s.findLadders("red", "tax", l);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}

