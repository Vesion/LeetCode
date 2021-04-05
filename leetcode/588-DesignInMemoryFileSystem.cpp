#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

class FileSystem {
public:
    struct Node {
        bool is_dir;
        string content;
        unordered_map<string, Node*> children;
    };
    Node* root;

    FileSystem() {
        root = new Node();
        root->is_dir = true;
    }

    vector<string> ls(string path) {
        istringstream in(path);
        string token;
        Node* node = root;
        while (getline(in, token, '/')) {
            if (token.empty()) continue;
            node = node->children[token];
        }
        if (node->is_dir) {
            vector<string> res;
            for (const auto& p : node->children) res.push_back(p.first);
            sort(res.begin(), res.end());
            return res;
        } else {
            return {token};
        }
    }

    void mkdir(string path) {
        istringstream in(path);
        string token;
        Node* node = root;
        while (getline(in, token, '/')) {
            if (token.empty()) continue;
            if (!node->children.count(token)) {
                Node* c = new Node();
                c->is_dir = true;
                node->children[token] = c;
            }
            node = node->children[token];
        }
    }

    void addContentToFile(string filePath, string content) {
        istringstream in(filePath);
        string token;
        Node* node = root;
        while (getline(in, token, '/')) {
            if (token.empty()) continue;
            if (!node->children.count(token)) {
                Node* c = new Node();
                c->is_dir = false;
                node->children[token] = c;
            }
            node = node->children[token];
        }
        node->content += content;
    }

    string readContentFromFile(string filePath) {
        istringstream in(filePath);
        string token;
        Node* node = root;
        while (getline(in, token, '/')) {
            if (token.empty()) continue;
            node = node->children[token];
        }
        return node->content;
    }
};


int main() {
    FileSystem fs;
    fs.mkdir("/a/b/c");
    fs.addContentToFile("/a/b/c/d", "hello");
    fs.addContentToFile("/a/b/e", "world");
    fs.addContentToFile("/a/b/f/g", "xx");
    fs.mkdir("/a/b/f/h");
    for (auto& e : fs.ls("/a/b/f/h")) cout << e << " "; cout << endl;
    cout << fs.readContentFromFile("/a/b/c/d");
    return 0;
}
