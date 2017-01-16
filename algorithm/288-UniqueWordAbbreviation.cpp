#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> m;

public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& w : dictionary) {
            int n = w.size();
            string a = w[0] + to_string(n) + w[n-1];
            m[a].insert(w);
        }
    }

    bool isUnique(string word) {
        int n = word.size();
        string a = word[0] + to_string(n) + word[n-1];
        return m[a].count(word) == m[a].size();
        
    }
};

int main() {
    return 0;
}
