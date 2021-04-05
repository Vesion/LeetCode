#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// straight forward, maintain a set of points in the trie
class StreamChecker {
    struct Node {
        bool end = false;
        Node* next[26] = {};
    };
    Node* root;
    vector<Node*> p;
public:
    StreamChecker(vector<string>& words) {
        root = new Node();
        for (const string& w : words) {
            Node* cur = root;
            for (char c : w) {
                if (cur->next[c-'a'] == nullptr) cur->next[c-'a'] = new Node();
                cur = cur->next[c-'a'];
            }
            cur->end = true;
        }
    }

    bool query(char c) {
        vector<Node*> np;
        bool f = false;
        // try each tracked pointer one by one, discard those that cannot continue to go
        for (Node* cur : p) {
            if (cur->next[c-'a']) {
                cur = cur->next[c-'a'];
                if (cur->end) f = true;
                np.push_back(cur);
            }
        }
        if (root->next[c-'a']) {
            if (root->next[c-'a']->end) f = true;
            np.push_back(root->next[c-'a']);
        }
        np.swap(p);
        return f;
    }
};


// Brilliant!
// Build the trie with reversed words, query the stream on the fly
class StreamChecker {
    struct Node {
        bool end = false;
        Node* next[26] = {};
    };
    Node* root;
    int maxl = 0;
    deque<char> s;
public:
    StreamChecker(vector<string>& words) {
        root = new Node();
        for (string& w : words) {
            reverse(w.begin(), w.end());
            maxl = max(maxl, (int)w.size());
            Node* cur = root;
            for (char c : w) {
                if (cur->next[c-'a'] == nullptr) cur->next[c-'a'] = new Node();
                cur = cur->next[c-'a'];
            }
            cur->end = true;
        }
    }

    bool query(char c) {
        s.push_front(c);
        if (s.size() > maxl) s.pop_back();
        Node* cur = root;
        for (char t : s) {
            if (cur->next[t-'a']) {
                cur = cur->next[t-'a'];
                if (cur->end) return true;
            } else break;
        }
        return false;
    }
};


int main() {
}
