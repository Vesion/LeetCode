#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& c1, const vector<int>& c2) { if (c1[1] == c2[1]) return c1[0] < c2[0]; return c1[1] < c2[1]; });
        priority_queue<int> pq;
        int t = 0;
        for (auto& c : courses) {
            t += c[0];
            pq.push(c[0]);
            if (t > c[1]) {
                t -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};


int main() {
    return 0;
}
