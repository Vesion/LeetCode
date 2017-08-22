#include <iostream>
#include <vector>
using namespace std;

// Learn to how to categorize a complex problem to some simple scenarios!

// Solution 1 : 2 categories, brilliant!!
/*
           b                              b
   +----------------+             +----------------+
   |                |             |                |
   |                |             |                | a
 c |                |           c |                |
   |                | a           |                |    f
   +----------------+-->          |                | <----+
            d       |             |                |      | e
                    |             |                       |
                                  +-----------------------+
                                               d
*/
// In both cases, d needs to be at least b. 
// In the first case to cross the a-line directly, and in the second case to get behind it so that the f-line can cross it. 
// So I factored out d >= b.
// The "special case" of the e-line stabbing the a-line from below is covered because in that case, the f-line "crosses" it (note that even if there is no actual f-line, my code uses f = 0 and thus still finds that "crossing").
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        for (int i : x) {
            f = e, e = d, d = c, c = b, b = a, a = i;
            if ((d >= b && b > 0) && (a >= c || (a+e >= c && c >= e && f+b >= d))) return true;
        }
        return false;
    }
};


int main() {
    vector<int> x = {3,3,3,2,1,1};
    return 0;
}
