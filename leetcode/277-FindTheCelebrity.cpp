#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

// Solution 1 : two pass
class Solution {
public:
    int findCelebrity(int n) {
        if (n <= 1) return -1;
        int candidate = 0;
        for (int i = 1; i < n; ++i)
            if (knows(candidate, i)) candidate = i;
        for (int i = 0; i < n; ++i)
            if (i != candidate && (knows(candidate, i) || !knows(i, candidate))) return -1;
        return candidate;
    }
};


// Solution 2 : stack, smart
class Solution_2 {
public:
    int findCelebrity(int n) {
        if (n <= 1) return -1;
        stack<int> st;
        for (int i = 0; i < n; ++i) st.push(i);

        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (knows(a, b)) st.push(b); // if a knows b, a must not be celebiry, b may be
            else st.push(a); // if a doesn't know b, b must not be celebiry, a may be
        }

        int candidate = st.top();
        for (int i = 0; i < n; ++i)
            if (i != candidate && (knows(candidate, i) || !knows(i, candidate))) return -1;
        return candidate;
    }
};



int main() {
    Solution s;
    return 0;
}
