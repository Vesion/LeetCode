#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string toGoatLatin(string sentence) {
        string res;
        istringstream in(sentence);
        string w;
        int i = 1;
        while (getline(in, w, ' ')) {
            if (w.empty()) continue;
            if (isvowel(w[0])) w += "ma";
            else w = w.substr(1) + w[0] + "ma";
            w += string(i++, 'a');
            res += w + " ";
        }
        res.pop_back();
        return res;
    }

    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

int main() {
}
