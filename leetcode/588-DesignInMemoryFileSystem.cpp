#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
#include <queue> 
using namespace std;

class FileSystem {
private:
    struct File {
        bool isFile;
        string name;
        string content;
        vector<File*> child;
        File() {}
        File(bool f, string n) : isFile(f), name(n) {}
    };
    File* root;

public:
    FileSystem() {
        root = new File(); 
    }
    
    vector<string> ls(string path) {
        istringstream in(path);
        string file;
        File* cur = root;
        while (getline(in, file, '/')) {
            bool f = false;
            for(File* c : cur->child) {
                if (c->name == file) { f = true; cur = c; break; }
            }
            if (!f) return {};
        }
        if (cur->isFile) return {cur->name};
        vector<string> res;
        for (File* c : cur->child) res.push_back(c->name);
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {
        istringstream in(path);
        string file;
        File* cur = root;
        while (getline(in, file, '/')) {
            bool f = false;
            for(File* c : cur->child) {
                if (c->name == file) { f = true; cur = c; break; }
            }
            if (!f) {
                File* t = new File(false, file);
                cur->child.push_back(t);
                cur = t;
            }
        }
    }
    
    void addContentToFile(string filePath, string content) {
        istringstream in(filePath);
        string file;
        File* cur = root;
        while (getline(in, file, '/')) {
            bool f = false;
            for(File* c : cur->child) {
                if (c->name == file) { f = true; cur = c; break; }
            }
            if (!f) {
                File* t = new File(false, file);
                cur->child.push_back(t);
                cur = t;
            }
        }
        cur->isFile = true;
        cur->content += content;
    }
    
    string readContentFromFile(string filePath) {
        istringstream in(filePath);
        string file;
        File* cur = root;
        while (getline(in, file, '/')) {
            bool f = false;
            for(File* c : cur->child) {
                if (c->name == file) { f = true; cur = c; break; }
            }
            if (!f) return "";
        }
        return cur->content;
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
