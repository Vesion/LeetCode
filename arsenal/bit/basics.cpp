#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
using namespace std;


// power of 2
int mul_pow_2(int n, int m) {
    return n << m;
}
int div_pow_2(int n, int m) {
    return n >> m;
}

// max/min
int max(int a, int b) {
    return b & ((a - b) >> 31) | a & (~(a - b) >> 31);
}
int min(int a, int b) {
    return a & ((a - b) >> 31) | b & (~(a - b) >> 31);
}

// sign
bool is_same_sign(int x, int y) {
  return (x ^ y) >= 0;
}

// set/unset/flip bit
int get_bit(int a, int b) {
    return (a >> b) & 1;
}
int set_bit(int a, int b) {
    return a | (1 << b);
}
int unset_bit(int a, int b) {
    return a & ~(1 << b);
}
int flip_bit(int a, int b) {
    return a ^ (1 << b);
}

// lowest set bit
int lowest_set_bit(int a) {  // 0b11100 -> 0b00100
    return a&-a;
}
int most_right_shift(int a) {  // 0b11100 -> 0b111
    return a / (a&-a);
}
int count_set_bits(int a) {
    int c = 0;
    while (a) {
        a -= (a&-a);  // used in BIT
        ++c;
    }
    return c;
}
void unset_lowest_set_bit(int& a) {
    a &= (a-1);
}
int count_set_bits2(int a) {
    int c = 0;
    while (a) {
        a &= (a-1);
        ++c;
    }
    return c;
}

// get all non-empty subsets of a
void subset(int a) {
    for (int i = a; i; i = (i-1) & a) {
        cout << bitset<4>(i) << endl;
    }
}


int main() {
    int a = 0b1111;
    subset(a);
}

