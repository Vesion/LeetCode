#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// divide and conquer, O(nlogn)
// for a range [i, j] in target, find the minimum index k,
// then the problem can be solved by solving two sub problems, [i, k-1], [k+1, j]
// find minimum in a range can be solved by segment tree in O(logn)
class Solution0 {
public:
    vector<int> tree;
    int build(vector<int>& arr,int start,int end,int i) {
        if(start==end)
            return tree[i]=start;
        else {
            int q=start+(end-start)/2;
            int left=build(arr,start,q,2*i+1);
            int right=build(arr,q+1,end,2*i+2);
            return tree[i]=arr[left]<arr[right]?left:right;
        }
    }
    int query(vector<int>& arr,int start,int end,int low,int high,int i) {
        if(start<=low&&end>=high)
            return tree[i];
        else if(high<start||end<low)
            return -1;
        else {
            int q=(high+low)/2;
            int left=query(arr,start,end,low,q,2*i+1);
            int right=query(arr,start,end,q+1,high,2*i+2);
            if(left==-1)
                return right;
            if(right==-1)
                return left;
            return arr[left]<arr[right]?left:right;
        }

    }
    int fun(int subArrVal,int start,int end,vector<int>& target) {
        // this updating the minimum value in the return array can be done optimally
        // by passing the current sub array value as a parameter.
        if(start<=end) {
            int q=query(target,start,end,0,target.size()-1,0);
            int val=target[q]-subArrVal;
            return val+fun(target[q],start,q-1,target)+fun(target[q],q+1,end,target);
        }
        else return 0;
    }
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x) - 1;
        tree.resize(max_size,-1);
        build(target,0,n-1,0);
        return fun(0,0,n-1,target);
    }
};

// O(n)
// whenever a number is larger than its previous one,
// we need at least (num-prev) operations to make the difference.
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int pre = 0, res = 0;
        for (int num : target) {
            res += max(0, num-pre);
            pre = num;
        }
        return res;
    }
};

int main() {

}