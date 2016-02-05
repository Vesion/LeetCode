#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string path) {
    if (path == "/")
        return path;
    path += "/"; // unify format, append a / to the end
    stack<string> ds;
    size_t cpos = 1;
    size_t spos = path.find("/", cpos);
    while (spos != string::npos) {
        string d = path.substr(cpos, spos-cpos);
        if (d.empty() || d == ".") {} // step over // and .
        else if (d == "..") { // pop
            if (!ds.empty()) ds.pop();
        }
        else { // push
            ds.push(d);
        }
        cpos = spos + 1;
        spos = path.find("/", cpos);
    }
    if (ds.empty()) return "/";
    string result;
    while (!ds.empty()) {
        result = ("/" + ds.top() + result);
        ds.pop();
    }
    return result;
}

int main() {
    cout << simplifyPath("/a/b") << endl;
    cout << simplifyPath("/b/////../.././././c/d/e") << endl;
    cout << simplifyPath("/...") << endl;
    return 0;
}
