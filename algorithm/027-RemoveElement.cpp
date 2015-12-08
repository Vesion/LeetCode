#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// use STL remove
int removeElement(vector<int>& nums, int val) {
    return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
}

int main() {
    vector<int> a{4, 5};
    cout << removeElement(a, 4);
    return 0;
}
