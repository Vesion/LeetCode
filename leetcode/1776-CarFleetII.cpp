#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// mono-decreasing stack
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1);
        stack<int> st;
        for (int i = n-1; i >= 0; --i) {
            int p0 = cars[i][0], v0 = cars[i][1];
            double t = -1;
            while (!st.empty()) {
                int j = st.top();
                int p1 = cars[j][0], v1 = cars[j][1];
                // p0+v0*t = p1+v1*t, t = (p1-p0)/(v0-v1)
                t = (p1-p0)*1.0/(v0-v1);
                if (v0 <= v1 || (res[j] > 0 && t >= res[j])) st.pop();
                else break;
            }
            if (!st.empty()) res[i] = t;
            st.push(i);
        }
        return res;
    }
};

int main() {

}