#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// use hashtable
vector<int> findSubstring(string s, vector<string>& words) {
    int wlen = words.begin()->size();
    int catlen = wlen * words.size();
    int slen = s.length();
    vector<int> result;

    if (slen < catlen)
        return result;

    // store times every word appears
    unordered_map<string, int> wordCount;
    for (auto w : words) ++wordCount[w];

    // traverse from begin to end-catlen
    for (auto i = begin(s); i <= prev(end(s), catlen); ++i) {

        // copy count table for unused words
        unordered_map<string, int> unused(wordCount);

        // traverse from i to i+catlen, search each wlen string in unused table
        for (auto j = i; j != next(i, catlen); j += wlen) {
            auto pos = unused.find(string(j, next(j, wlen)));

            // if not found, loop over
            if (pos  == unused.end() || pos->second == 0)
                break;

            // if found, decrease this word's count by 1, and if count to 0, remove this word
            if (--pos->second == 0)
                unused.erase(pos);
        }

        // if all words found, it is a result
        if (unused.size() == 0)
            result.push_back(distance(begin(s), i));
    }

    return result;
}

int main() {
    string s("barfoothefoobarman");
    vector<string> v{"foo", "bar"};
    for (auto i : findSubstring(s, v)) {
        cout << i << endl;
    }
    return 0;
}
