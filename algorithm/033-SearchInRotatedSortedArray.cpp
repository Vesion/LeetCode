#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int binarySearch(vector<int>::iterator begin, vector<int>::iterator end, int val) {
    auto first = begin, last = end;
    while (first <= last) {
        auto mid = first + distance(first, last) / 2;
        if (*mid == val)
            return distance(begin, mid);
        if (*mid > val)
            last = prev(mid);
        else
            first = next(mid);
    }
    return -1;
}

// firstly find the pivot, then search each part respectively
int search(vector<int>& nums, int target) {
    auto first = nums.begin(), last = nums.end();
    if (first == last)
        return -1;
    --last;
    if (first == last)
        return (target == *first ? 0 : -1);
    int result;
    auto pivot = last;
    while (first + 1 != nums.end()) {
        if (*first < *(first + 1)) ++first;
        else {pivot = first; break;}
        if (*(last - 1) < *last) --last;
        else {pivot = last - 1; break;}
    }
    result = binarySearch(nums.begin(), pivot, target);
    if (result == -1) {
        result = binarySearch(pivot+1, nums.end()-1, target);
        if (result != -1)
            result = distance(nums.begin(), pivot) + result + 1;
    }
    return result;
}

// in just one funtion
//int search(int A[], int n, int target) {
    //int first = 0, last = n;
    //while (first != last) {
        //const int mid = first  + (last - first) / 2;
        //if (A[mid] == target)
            //return mid;
        //if (A[first] <= A[mid]) {
            //if (A[first] <= target && target < A[mid])
                //last = mid;
            //else
                //first = mid + 1;
        //} else {
            //if (A[mid] < target && target <= A[last-1])
                //first = mid + 1;
            //else
                //last = mid;
        //} 
    //}
    //return -1; 
//}


int main() {
    //vector<int> a{4, 5, 6, 7, 0, 1, 2};
    vector<int> a{1, 3};
    cout << search(a, 0) << endl;
    return 0;
}
