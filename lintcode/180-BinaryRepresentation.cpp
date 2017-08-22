#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string binaryRepresentation(string n) {
        long integer = 0;
        double fraction = 0.0;
        auto point_pos = n.find('.');
        if (point_pos != 0) integer = stol(n.substr(0, point_pos));
        if (point_pos != string::npos) fraction = stod(n.substr(point_pos));

        string ri = "";
        if (integer == 0)  ri = "0";
        while (integer) {
           ri += ('0' + integer % 2);
           integer /= 2;
        }
        reverse(ri.begin(), ri.end());
        if (fraction > 0.0) ri += '.';

        string rf = "";
        while (fraction > 0.0) {
            if (rf.size() > 32) return "ERROR";
            fraction *= 2;
            if (fraction >= 1.0) {
                rf += '1';
                fraction -= 1.0;
            } else
                rf += '0';
        }

        return ri + rf;
    }
};

int main() {
    Solution s;
    cout << s.binaryRepresentation(".625") << endl;
    return 0;
}
