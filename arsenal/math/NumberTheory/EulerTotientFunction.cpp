#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// Euler’s Totient function phi(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n, 
//      i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.
//
// Properties:
//      1. For a prime number p, phi(p) = p-1
//      2. Fow two coprime number a and b, phi(a*b) = phi(a)*phi(b)
//      3. For any two prime numbers p and q, phi(p*q) = (p-1)*(q-1), used in RSA
//      4. For a prime number p, phi(p^k) = p^k - p^(k-1)
//      5. The most important property:
//              Euler's Theorem: 
//                  If n and a are coprime numbers, a^phi(n) = 1 (mod n)
//              Fermat's Little Theorem (the particular case of Euler's Theorem):
//                  If p is prime number, a^(p-1) = 1 (mod p)
//
// Applications:
//      1. When calculating the modular exponentiation with very large exponent, we can use ETF to reduce it.
//          e.g. a^b = x (mod m), b < 1e1000 how to calculate x?
//              if gcd(a, m) == 1, a^b % m = a^(b%phi(m)) % m
//              if gcd(a, m) != 1, a^b % m = a^(b%phi(m)+phi(m)) % m
//              

using ll = long long;

// calculate phi(n) individually
ll f_phi(ll n) {
    ll res = n;
    for (ll i = 2; i <= sqrt(n); ++i) {
        if (n%i == 0) {
            while (n%i == 0) n /= i;
            res -= res/i;
        }
    }
    if (n > 1) res -= res/n;
    return res;
}


// get the phi table
const int MAXN = 1e5;
int phi[MAXN];

void get_phi_table() {
    phi[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (!phi[i]) {
            for (int j = i; j < MAXN; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] -= phi[j]/i;
            }
        }
    }
}


int main() {
    for (ll n = 1; n <= 20; ++n) cout << f_phi(n) << endl; 
    get_phi_table();
    for (int i = 1; i <= 20; ++i) cout << phi[i] << endl;
    return 0;
}
