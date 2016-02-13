#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Gray Code (格雷码), refer to wiki 'gray code', very classical problem
//
// binary code --> gray code
//      g[0] = b[0], g[i] = b[i] ^ b[i-1] (^ is XOR operator)
//      e.g. b(1001) --> g(1101)
//
// gray code --> binary code
//      b[0] = g[0], b[i] = g[i] ^ b[i-1]
//      e.g. g(1000) --> b(1111)
//
// decimal --> gray code
//      n = g(n ^ (n / 2))


// Solution 1 : use formula, a decimal number n --> g(n^(n/2))
vector<int> grayCode_formula(int n) {
    vector<int> result;
    const size_t len = 1 << n;
    result.reserve(len);
    for (size_t i = 0; i < len; ++i) {
        int r = i ^ (i >> 1); // formula
        result.push_back(r);
    }
    return result;
}


// Solution 2 : use n codes to generate next n codes, increase by (double) times
vector<int> grayCode_r(int n) {
    vector<int> result;
    result.reserve(1<<n);
    result.push_back(0); // the first one
    for (int i = 0; i < n; ++i) {
        int highest_bit = 1 << i;
        for (int j = result.size()-1; j >= 0; --j) // here iterate from right to left to ensure symmetry
            result.push_back(highest_bit | result[j]);
    }
    return result;
}

int main() {
    //auto r = grayCode_formula(3);
    auto r = grayCode_r(3);
    cout << endl <<"main : " << endl;
    for (auto i : r)
        cout << i << " ";
    cout << endl;
    return 0;
}
