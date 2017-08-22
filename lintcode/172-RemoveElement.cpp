#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int> &A, int elem) {
        int i = 0;
        int first = 0, last = A.size();
        while (first != last) {
            if (A[first] != elem) A[i++] = A[first];
            ++first;
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 3, 4, 1, 2, 3, 4};
    cout << s.removeElement(a, 3) << endl;
    return 0;
}
