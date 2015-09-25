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

// time limit exceeded
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

int main() {
    vector<int> p;
    p.push_back(1);
    p.push_back(2);
    p.push_back(3);
    p.push_back(4);
    cout<<maxArea2(p)<<endl;
    return 0;
}
