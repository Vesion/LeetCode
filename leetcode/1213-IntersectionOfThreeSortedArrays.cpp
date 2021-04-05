#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// binary search
class Solution1 {
public:
    vector<int> arraysIntersection(vector<int>& a1, vector<int>& a2, vector<int>& a3) {
        vector<int> res;
        for (int num : a1) {
            if (binary_search(a2.begin(), a2.end(), num) &&
                binary_search(a3.begin(), a3.end(), num)) {
                res.push_back(num);
            }
        }
        return res;
    }
};


// 3 pointers
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& a1, vector<int>& a2, vector<int>& a3) {
        int n1 = a1.size(), n2 = a2.size(), n3 = a3.size();
        vector<int> res(n1);
        int d = 0;
        for (int i = 0, j = 0, k = 0; i < n1; ++i) {
            while (j < n2 && a2[j] < a1[i]) ++j;
            while (k < n3 && a3[k] < a1[i]) ++k;
            if (j < n2 && a2[j] == a1[i] && k < n3 && a3[k] == a1[i]) {
                res[d++] = a1[i];
            }
        }
        res.resize(d);
        return res;
    }
};

int main() {
}
