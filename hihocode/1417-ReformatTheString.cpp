#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string reformat(string s) {
        string a, d;
        for(char c : s) {
            if (isdigit(c)) d += c;
            else a += c;
        }
        if (abs(int(a.size()) - int(d.size())) > 1) return "";

        bool f = a.size() > d.size();
        for (int i = 0, j = 0, k = 0; i < a.size() || j < d.size(); ) {
            if (f) s[k++] = a[i++];
            else s[k++] = d[j++];
            f = !f;
        }
        return s;
    }
};

int main() {

}
