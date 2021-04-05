#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// sort
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for (const string& s : folder) {
            if (res.empty() || !subfolder(s, res.back())) res.push_back(s);
        }
        return res;
    }

    bool subfolder(const string& s, const string& p) {
        int i = 0;
        for (; i < s.size(); ++i) {
            if (i == p.size()) break;
            if (s[i] != p[i]) return false;
        }
        return s[i] == '/';
    }
};

// sort + trie
class Solution1 {
    struct Node {
        bool end = false;
        unordered_map<string, Node*> next;
    };
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(),
             [](const string& f1, const string& f2) {
                 return f1.size() < f2.size();
             });
        vector<string> res;
        Node root;
        for (const string& f : folder) {
            Node* cur = &root;
            string dir;
            istringstream in(f);
            bool is_sub = false;
            while (getline(in, dir, '/')) {
                if (dir.empty()) continue;  // skip the first token
                auto it = cur->next.find(dir);
                if (it == cur->next.end()) {
                    Node* new_node = new Node();
                    cur->next[dir] = new_node;
                    cur = new_node;
                } else if (it->second->end) {
                    is_sub = true;
                    break;
                } else {
                    cur = it->second;
                }
            }
            if (is_sub) continue;
            cur->end = true;
            res.push_back(f);
        }
        return res;
    }
};


int main() {
}