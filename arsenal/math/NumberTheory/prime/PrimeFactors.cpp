#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Problem:
//      Given a positive number N, find all prime factors of it.


vector<int> primeFactors(int n) {
    vector<int> res;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            res.push_back(i);
            while (n%i == 0) n /= i;
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}


int main() {
    auto r = primeFactors(4); 
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
