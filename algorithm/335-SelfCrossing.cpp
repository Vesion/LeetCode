#include <iostream>
#include <vector>
using namespace std;

// Learn to how to categorize a complex problem to some simple scenarios!

// Solution 1 : 3 categories
// Categorize the self-crossing scenarios, there are 3 of them: 
// 1. Fourth line crosses first line and so on...
// 2. Fifth line meets first line and so on...
// 3. Sixth line crosses first line and so on...
// Intuitively:
/*               
    case 1 :    __2__
                |   | 1
              3 |___|____ 
                    | 4

    case 2 :    __2__
                |   | 1
              3 |   |
                |   |<----(overlap)
                |_4_| 5

    case 3 :    __2__
                |   | 1
              3 |   |___6_
                |         | 
                |_4_______|5

*/

bool isSelfCrossing_3(vector<int>& x) {
    int n = x.size();
    if (n < 4) return false;
    for (int i = 3; i < n; ++i) {
        if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true; // case 1
        if (i >= 4 && x[i-1] == x[i-3] && x[i]+x[i-4] >= x[i-2]) return true; // case 2
        if (i >= 5 && x[i-2] >= x[i-4] && x[i-1] <= x[i-3] && x[i-1]+x[i-5] >= x[i-3] && x[i]+x[i-4] >= x[i-2]) return true; // case 3
    }
    return false;
}


// Solution 2 : 2 categories
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
// In both cases, d needs to be at least b. In the first case to cross the a-line directly, and in the second case to get behind it so that the f-line can cross it. So I factored out d >= b.
// The "special case" (case2 in Solution 1) of the e-line stabbing the a-line from below is covered because in that case, the f-line "crosses" it (note that even if there is no actual f-line, my code uses f = 0 and thus still finds that "crossing").
bool isSelfCrossing_2(vector<int>& x) {
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    for (int i : x) {
        f = e, e = d, d = c, c = b, b = a, a = i;
        if ((d >= b && b > 0) && (a >= c || (a+e >= c && c >= e && f+b >= d))) return true;
    }
    return false;
}


int main() {
    vector<int> x = {3,3,3,2,1,1};
    cout << isSelfCrossing_2(x) << endl;
    cout << isSelfCrossing_3(x) << endl;
    return 0;
}
