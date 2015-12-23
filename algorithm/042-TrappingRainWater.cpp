#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap0(vector<int>& a) {
    stack<pair<int, int>> s;
    int water = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int height = 0;
        while (!s.empty()) { // 将栈里比当前元素矮或等高的元素全部处理掉 
            int bar = s.top().first;
            int pos = s.top().second;
            // bar, height, a[i] 三者夹成的凹陷
            water += (min(bar, a[i]) - height) * (i - pos - 1);
            cout << "water " << water << endl;
            height = bar;
            if (a[i] < bar) // 碰到了比当前元素高的,跳出循环 
                break;
            else
                s.pop(); // 弹出栈顶,因为该元素处理完了,不再需要了
        }
        s.push(make_pair(a[i], i));
    }
    return water;
}

// solution1: use a stack to store bars
//      if current bar is smaller than top one, push it
//      else solve all bars which are greater than or equal to current bar, and pop them
// O(n) O(n)
int trap_stack(vector<int>& height) {
    if (height.size() == 0)
        return 0;
    stack<int> bars; // store index, not real height
    int water = 0;
    for (int i = 0; i < height.size(); ++i) {
        int bottom = 0;
        while (!bars.empty()) {
            int left_pos = bars.top();
            int left = height[left_pos];
            int right_pos = i;
            int right = height[i];

            water += (min(left, right) - bottom) * (right_pos - left_pos - 1);
            cout << "i " << i << " water " << water << endl;
            
            bottom = left;
            if (height[i] >= left)
                bars.pop();
            else
                break; // if height[i] is smaller than bars's top, ignore
        }
        bars.push(i);
    }
    return water;
}

int main() {
    vector<int> a({10, 9, 8, 7, 8});
    cout << trap_stack(a) << endl;
    return 0;
}
