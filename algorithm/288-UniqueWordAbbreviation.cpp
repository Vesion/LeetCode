#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> abbrs;
        
    string getAbbr(string& word) {
        if (word.empty()) return word;
        return word.front() + to_string(word.size()) + word.back();
    }
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary) {
            string abbr = getAbbr(word);
            abbrs[abbr].insert(word);
        }
    }

    // here unique means:
    //      1. word is not in dictionary and its abbr is different from every word in dictionary
    //      2. word is in dictionary, but it's abbr is different from every other word in dictionary
    bool isUnique(string word) {
        string abbr = getAbbr(word);
        return abbrs[abbr].count(word) == abbrs[abbr].size();
    }
};

int main() {
    return 0;
}
