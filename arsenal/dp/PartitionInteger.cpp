#include <iostream>
using namespace std;

// Ineger Partition is a very classical dp problem.
// https://en.wikipedia.org/wiki/Partition_(number_theory)

// Version 1 : general
// optimal sub structure: f(n, m), n is the number to be partitioned, m is the maximum number after partitioned
//      f(n, m) = 1,                     (n == 1 or m == 1)   case 1 : n -> {n}
//                f(n, n),               (n < m)              case 2 : 
//                1 + f(n, m-1),         (n == m)             case 3 : include n or not
//                f(n-m, m) + f(n, m-1), (n > m)              case 4 : include m or not
int partition_all(int n, int m) {
    if (n == 1 || m == 1) return 1; 
    if (n < m) return partition_all(n, n);
    if (n == m) return 1 + partition_all(n, m-1);
    return partition_all(n-m, m) + partition_all(n, m-1);
}

int partition_all(int n) {
    return partition_all(n, n);
}


// Version 2 : each number can be used only once, that is unique
// Compared with version 1, we only need to change case 1 and case 4
//      f(n, m) = 1, (m == 1) 
//                0, (n == 1)
//                f(n-m, m-1) + f(n, m-1), (n > m)
int partition_unique(int n, int m) {
    if (n == 1) return 1;
    if (m == 1) return 0;
    if (n < m) return partition_unique(n, n);
    if (n == m) return 1 + partition_unique(n, m-1);
    return partition_unique(n-m, m-1) + partition_unique(n, m-1); // unique
}

int partition_unique(int n) {
    return partition_unique(n, n);
}


int main() {
    cout << partition_all(2) << endl;
    cout << partition_unique(5) << endl;
    return 0;
}
