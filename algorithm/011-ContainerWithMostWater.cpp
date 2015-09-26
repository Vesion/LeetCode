#include <iostream>
#include <vector>
using namespace std;

// common solution
// time limit exceeded
int maxArea1(vector<int> &height) {
    int maxarea = 0;
    for (int i = 1; i < height.size(); ++i) {
        for (int j = i-1; j >= 0; --j) {
            int h = min(height[i], height[j]);
            int area = h * (i - j);
            if (area > maxarea)
                maxarea = area;
        } 
    }
    return maxarea;
}

// ditto, time limit exceeded
int maxArea2(vector<int> &height) {
    int maxarea = 0;
    for (int w = 1; w <= height.size()-1; ++w) {
        int maxh = 0;
        for (int i = 0; i+w < height.size(); ++i) {
            int j = i + w;
            int h = min(height[i], height[j]);
            if (h > maxh)
                maxh = h;
        }
        int area = maxh * w;
        if (area > maxarea)
            maxarea = area;
    }
    return maxarea;
}

// solutions above are O(n2), beacause they calculate all area cases
// we can use `two pointer` scan from two sides to middle, 
int maxArea(vector<int> &height) {
    int maxarea = 0;
    int left = 0, right = height.size()-1;
    while (left < right) {
        int area = (right-left) * min(height[left], height[right]);
        if (area > maxarea)
            maxarea = area;
        // because the area is decided by the shorter edge
        // so we increase the shorter edge is to increase the area
        //
        //     height[left] < height[right] ? left++ : right-- ;
        //
        // However, this could cause the unnecessary `area` cacluation
        // We can do some improvement as below:
        if (height[left] < height[right]) {
            do {
                left++;
            } while (left < right && height[left-1] >= height[left]);
        } else {
            do {
                right--;
            } while (left < right && height[right+1] >= height[right]);
        }
    }
    return maxarea;
}

int main() {
    vector<int> p;
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);
    p.push_back(4);
    cout<<maxArea(p)<<endl;
    return 0;
}
