#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// use STL remove
int removeElement(vector<int>& nums, int val) {
    return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
}

// implement STL remove manually
vector<int>::iterator remove(vector<int>::iterator first, vector<int>::iterator last, int val) {
    vector<int>::iterator result = first;
    while (first != last) {
        if (*first != val) {
            *result = *first;
            ++result;
        }
        ++first;
    }
    return result;
}

int main() {
    vector<int> a{4, 5};
    cout << removeElement(a, 4);
    return 0;
}
