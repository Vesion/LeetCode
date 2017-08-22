#include <iostream>
#include <cstdio> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

int N;

struct Func {
    string name, start, end;
    Func(string n, string s, string e) : name(n), start(s), end(e) {}
};

int to_seconds(string t) {
    int secs = 0;
    for (int i = 0; i < 8; i += 3)
        secs = secs * 60 + ((t[i]-'0')*10+(t[i+1]-'0'));
    return secs;
}

string elapse(Func* f) {
    int diff = to_seconds(f->end) - to_seconds(f->start);
    int h = diff / 3600; diff %= 3600;
    int m = diff / 60; diff %= 60;
    int s = diff;
    char result[10];
    sprintf(result, "%02d:%02d:%02d", h, m, s);
    return string(result);
}


stack<Func*> st;
vector<Func*> path;

int main() {
    ios::sync_with_stdio(false);
    cin >> N; 
    while (N--) {
        string name, stamp, action;
        cin >> name >> stamp >> action;
        if (action == "START") {
            if (st.empty() || st.top()->name != name) {
                Func *f = new Func(name, stamp, " ");
                st.push(f);
                path.push_back(f);
            }
            else {
                cout << "Incorrect performance log" << endl;
                return 0;
            }
        }
        else {
            if (!st.empty() && st.top()->name == name && st.top()->start <= stamp) {
                Func* f = st.top();
                f->end = stamp;
                st.pop();
            }
            else {
                cout << "Incorrect performance log" << endl;
                return 0;
            }
        }
    }

    if (!st.empty())
        cout << "Incorrect performance log" << endl;
    else {
        for (Func* f : path) {
            cout << f->name << " " << elapse(f) << endl;
        }
    }
    return 0;
}
