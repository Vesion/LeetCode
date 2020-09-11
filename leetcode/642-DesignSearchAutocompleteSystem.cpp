#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>
#include <queue>
using namespace std;

class AutocompleteSystem {
public:
    struct Node {
        unordered_map<char, Node*> next;
        int freq = 0;
        Node() {}
    };
    Node* root = nullptr;
    Node* track = nullptr;
    string prefix;

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        if (sentences.empty()) return;
        root = new Node();
        for (int i = 0; i < sentences.size(); ++i) {
            const string& s = sentences[i];
            const int t = times[i];
            if (t <= 0) continue;
            Node* cur = root;
            for (char c : s) {
                if (!cur->next.count(c)) cur->next[c] = new Node();
                cur = cur->next[c];
            }
            cur->freq += t;
        }
        track = root;
        prefix = "";
    }

    using P = pair<int, string>;
    struct Cmp {
        bool operator() (const P& p1, const P& p2) {
            if (p1.first != p2.first) return p1.first > p2.first;
            return p1.second < p2.second;
        }
    };

    vector<string> input(char c) {
        if (!track->next.count(c)) {
            if (c == '#') {
                track->freq++;
                track = root;
                prefix = "";
            } else {
                track->next[c] = new Node();
                track = track->next[c];
            }
            return {};
        } else {
            track = track->next[c];

            priority_queue<P, vector<P>, Cmp> top3;
            string path(1, c);
            dfs(track, path, top3);
            assert(!top3.empty());

            vector<string> res;
            while (!top3.empty()) {
                res.push_back(prefix + top3.top().second);
                top3.pop();
            }
            reverse(res.begin(), res.end());
            prefix += c;
            return res;
        }
    }

    void dfs(Node* cur, string& path, priority_queue<P, vector<P>, Cmp>& top3) {
        assert(cur != nullptr);
        if (cur->freq && !path.empty()) {
            top3.push({cur->freq, path});
            if (top3.size() > 3) top3.pop();
        }
        for (const auto& p : cur->next) {
            path.push_back(p.first);
            dfs(p.second, path, top3);
            path.pop_back();
        }
    }
};

int main() {
    vector<string> s = {"abc", "abbc", "a"};
    vector<int> t = {3,3,3};
    AutocompleteSystem a(s, t);

    string x = "abc#";
    for (char d : x) {
        auto res = a.input(d);
        for (const string& r : res) cout << r << endl;
        cout << endl;
    }
    return 0;
}

