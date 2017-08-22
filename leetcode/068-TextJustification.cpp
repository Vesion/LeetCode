#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (words.empty()) return {};
        int n = words.size();
        vector<string> res;
        int i = 0;
        while (i < n) {
            vector<string> row;
            int len = words[i].size();;
            row.push_back(words[i++]);
            while (i < n && len+(int)words[i].size()+1 <= maxWidth) {
                row.push_back(words[i]);
                len += words[i].size()+1;
                ++i;
            }

            int extras = maxWidth - len;
            int slots = row.size()-1;
            string r = row[0];
            if (slots == 0 || i == n) {
                for (int j = 1; j < (int)row.size(); ++j)
                    r += string(1, ' ') + row[j];
                if ((int)r.size() < maxWidth) r += string(maxWidth-r.size(), ' ');
            } else {
                int spaces = 1 + extras / slots;
                extras %= slots;
                for (int j = 1; j < (int)row.size(); ++j)
                    r += string(spaces + (extras-- > 0 ? 1 : 0), ' ') + row[j];
            }
            res.push_back(r);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> w = {"This", "is", "an", "exaasdfaaaample", "of", "text", "justific.", "a"};
    auto r = s.fullJustify(w, 16);
    for (auto& e : r) cout << e << endl; cout << endl; 
    return 0;
}

