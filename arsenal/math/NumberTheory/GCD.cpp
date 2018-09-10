#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The basical greatest common divisor problem.
//
// Euclid Algorithm:
//      gcd(a, b) = gcd(b, a % b)
//
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// least common multiple
int lcm(int a, int b) {
    return a*b / gcd(a, b);
}


// 扩展欧几里得算法 (Extend Euclid Algorithm)
//      gcd(a, b) = a * x + b * y
//
int extend_Euclid(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extend_Euclid(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

// 将 a*x + b*y = gcd(a, b) 看做二元不定方程，则上述扩展欧几里得算法可以求出该方程的一组特解 x0, y0
// 则通解的形式为：
//      x = x0 + b/gcd * t
//      y = y0 - a/gcd * t


// 扩展欧几里得算法可以用来求解以下问题：
// 1. 形如 a*x + b*y = c 的不定方程
// 2. 形如 a*x = b mod n 的模线性方程（或线性同余方程）
// 3. 形如 a*x = 1 mod n 的模的逆元（或模倒数）

// 1. 求解不定方程 a*x + b*y = c
// 直接用extend_Euclid求出gcd，若c不是gcd的整数倍则无解
bool linear_equation(int a, int b, int c, int& x0, int& y0) {
    int x, y;
    int g = extend_Euclid(a, b, x, y);
    if (c % g) return false; // 无解
    int k = c / g;
    x0 = x * k, y0 = y * k; // 一组特解
    return true;
}

// 2. 求解模线性方程 a*x = b mod n
// a*x - n*y = b
bool modulo_linear_equation(int a, int b, int n, int& x0) {
    int x, y;
    int g = extend_Euclid(a, n, x, y);
    if (b % g) return false; // 无解
    int k = b / g;
    x0 = (x * k) % n; // 特解
    return true;
}

// 3. 求解模倒数 a*x = 1 mod n, 无解或唯一解
// a*x - n*y = 1
bool modulo_inverse(int a, int n, int& x0) {
    int x, y;
    int g = extend_Euclid(a, n, x, y);
    if (g > 1) return false; // 无解
    x0 = x % n; // 唯一解，模倒数
    return true;
}


int main() {
    cout << gcd(8, 6) << endl; 

    int x, y;
    extend_Euclid(3, 5, x, y);
    cout << x << " " << y << endl;
    
    modulo_inverse(3, 5, x);
    cout << x << endl;
    return 0;
}
