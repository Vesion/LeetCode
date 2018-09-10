#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// Judge a integer if it is a prime number or not.
//
// Prime numbers table [1, 100]
int small_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};


// Solution 0 : brute force
// iterate from 1 to sqrt(n)
bool is_prime_bf(int n) {
    if (n < 2) return true;
    for (int i = 2; i*i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}



// Solution 1 : calculate prime table with sieve
//
const int MAX = 1e5+5;
bool is_prime[MAX];


// Solution 1.1 : Sieve of Eratosthenes 埃式筛法, O(n * loglogn)
void get_prime_table_Er() {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i+i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }
}


// Solution 1.2 : Sieve of Euler 欧拉筛法, O(n)
int p[MAX];
void get_prime_table_Eu() {
    memset(is_prime, true, sizeof is_prime);
    memset(p, 0, sizeof p);
    is_prime[0] = is_prime[1] = false;
    int cnt = 0;
    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) p[cnt++] = i;
        for (int j = 0; j < cnt; ++j) {
            int t = i * p[j]; // improvement 1 : use prime numbers to multiply current number
            if (t >= MAX) break;
            is_prime[t] = false;
            if (i % p[j] == 0) break; // improvement 2 : stop early
        }
    }
}


// Solution 2 : Miller Rabin test, 
// based on Fermat's Little Theorem :
//      If p is a prime number, then for any integer a, a^p = a mod p 
//                      if a is not divisible by p, a^(p-1) = 1 mod p


int main() {
    get_prime_table_Eu();
    //for (int i = 0; i < MAX; ++i);
        //if (is_prime[i]) cout << i << " ";
    cout << endl;
    return 0;
}
