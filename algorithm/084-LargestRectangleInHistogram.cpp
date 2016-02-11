#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution 1 : divide-and-conquer, O(n^2)
// for each part, scan from left to right, find the lowest one, partition the part with it,
// calculate bottom area, and left, right area recursively, we want the maximum of them three.
//
// TLE!! due to redundant scan in partition
int partition(vector<int>& heights, int left, int right) {
    int mid = left;
    int minHeight = INT_MAX;
    for (int i = left; i <= right; ++i) {
        if (heights[i] < minHeight) {
            minHeight = heights[i];
            mid = i;
        }
    }
    return mid;
}

int getArea(vector<int>& heights, int left, int right) {
    if (left > right) return 0;
    if (left == right) return heights[left];
    int min_index = partition(heights, left, right);
    int bottom_area = (right - left + 1) * heights[min_index];
    int left_area = getArea(heights, left, min_index-1);
    int right_area = getArea(heights, min_index+1, right);
    int max_area = max(max(left_area, right_area), bottom_area);
    return max_area;
}

int largestRectangleArea_dac(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    if (n == 1) return heights[0];
    return getArea(heights, 0, n-1);
}


// Solution 2 : 与011-ContainerWithMostWater类似，对每个柱子，左右扩展，直到碰到比自己矮的，计算这个举行的面积，记录最大值
// 同样是O(n^2)的，会超时，这里不实现


// Solution 3 : use stack, O(n)
// 参考题解，不太容易想到，有点类似于042-TrappingRainWater中利用栈的思路
int largestRectangleArea_stack(vector<int>& heights) {
    if (heights.empty()) return 0; 
    stack<int> hs;
    heights.push_back(0);
    int maxArea = 0;
    for (int i = 0; i < heights.size(); ) {
        if (hs.empty() || heights[i] > heights[hs.top()]) {
            hs.push(i++);
        }
        else {
            int tmp = hs.top();
            hs.pop();
            maxArea = max(maxArea, heights[tmp] * (hs.empty() ? i : i - hs.top() - 1));
        }
    }
    return maxArea;
}

// Solution 3改进版，用数组替换栈，飞起
int largestRectangleArea_array(vector<int>& heights) {
    heights.push_back(0); 
    int len = heights.size(), res = 0, cur = 1;
    vector<int> hs(len+1, 0);
    hs[0] = -1;
    for(int i = 1; i < len; ++i){
        while(cur && heights[i] < heights[hs[cur]]) {
            int h = heights[hs[cur]];
            int w = i - hs[--cur] - 1;
            res = max(res, h * w);
        }
        hs[++cur]=i;
    }
    return res;
}

int main() {
    vector<int> heights({1, 2, 3, 4});
    cout << largestRectangleArea_dac(heights) << endl;
    cout << largestRectangleArea_stack(heights) << endl;
    cout << largestRectangleArea_array(heights) << endl;
    return 0;
}
