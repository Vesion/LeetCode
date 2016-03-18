#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Soluton 1 : sort, trivial, O(nlgn) time, O(1) space
int hIndex_sort(vector<int>& citations) {
    if (citations.empty()) return 0;
    sort(citations.begin(), citations.end(), [](int a, int b) { return a > b; });
    int i;
    for (i = 1; i <= citations.size(); ++i)
        if (citations[i-1] < i) break;
    return i-1;
}


// Solution 2 : hash table, like count sort, O(n) time, O(n) space
int hIndex_count(vector<int>& citations) {
    if (citations.empty()) return 0;
    int n = citations.size();
    vector<int> count(n+1, 0);
    for (auto & c : citations) {
        if (c > n) ++count[n];
        else ++count[c];
    }
    int i, total = 0;
    for (i = n; i >= 0; --i) {
        total += count[i];
        if (total >= i) return i;
    }
    return 0;
}

int main() {
    vector<int> citations = {0, 1};
    cout << hIndex_sort(citations) << endl;
    cout << hIndex_count(citations) << endl;
    return 0;
}
