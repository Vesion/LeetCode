#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

class Solution {
public:

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        if (start == end) return {{start}};

        vector<vector<string>> result;
        vector<string> path;
        unordered_set<string> forwards, backwards;
        unordered_map<string, vector<string>> tree;

        path.push_back(start);
        forwards.insert(start);
        backwards.insert(end);

        if (buildTree(forwards, backwards, dict, tree, false))
            getPath(start, end, tree, path, result);
        return result;
    }

    bool buildTree(unordered_set<string> &forwards, unordered_set<string> &backwards, unordered_set<string> &dict, unordered_map<string, vector<string>> &tree, bool reversed) {
        if (backwards.empty()) return false;
        if (backwards.size() > forwards.size())
            return buildTree(backwards, forwards, dict, tree, !reversed);

        for (auto &s : forwards) dict.erase(s);
        for (auto &s : backwards) dict.erase(s);

        unordered_set<string> nextLevel;
        bool done = false;
        for (auto &s : forwards) {
            string word = s;
            for (auto &c : word) {
                char c0 = c;
                for (c = 'a'; c <= 'z'; ++c) {
                    if (c != c0) {
                        if (backwards.count(word)) {
                            done = true;
                            !reversed ? tree[s].push_back(word) : tree[word].push_back(s);
                        }
                        else if (!done && dict.count(word)) {
                            nextLevel.insert(word);
                            !reversed ? tree[s].push_back(word) : tree[word].push_back(s);
                        }
                    }
                }
                c = c0;
            }
        }
        return done || buildTree(nextLevel, backwards, dict, tree, reversed);
    }

    void getPath(string& start, string& end, unordered_map<string, vector<string>> &tree, vector<string> &path, vector<vector<string>> &result) {
        if (start == end) {
            result.push_back(path);
            return;
        }
        for (auto &s : tree[start]) {
            path.push_back(s);
            getPath(s, end, tree, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    auto r = s.findLadders("hit", "cog", dict);
    for (auto i : r) {
        for (auto j :i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
