#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// GCD of all counters
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> c;
        for (int d : deck) c[d]++;
        int gcd0 = deck.size();
        for (const auto& p : c) gcd0 = gcd(gcd0, p.second);
        return gcd0 > 1;
    }
};

// Brute-force compute common divisor of all counters
class Solution1 {
public:
    vector<int> primes() {
        constexpr int MAX = 1e4+1;
        vector<bool> is_prime(MAX, true);
        is_prime[0] = is_prime[1] = false;
        vector<int> res;
        for (int i = 2; i*i < MAX; ++i) {
            if (is_prime[i]) {
                for (int j = i+i; j < MAX; j += i)
                    is_prime[j] = false;
                res.push_back(i);
            }
        }
        return res;
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> c;
        for (int i : deck) ++c[i];

        static vector<int> ps = primes();
        for (int prime : ps) {
            bool f = true;
            for (const auto& p : c) {
                if (p.second % prime) {
                    f = false;
                    break;
                }
            }
            if (f) return true;
        }
        return false;
    }
};


int main() {
    return 0;
}
