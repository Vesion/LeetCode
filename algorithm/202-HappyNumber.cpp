#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int square(int x) { return x*x; }


// Solution 1 : use hashset, trivial
bool isHappy_set(int n) {
    unordered_set<int> s;
    while (true) {
        int t = 0;
        while (n) {
            t += square(n%10);
            n /= 10;
        }
        if (t == 1) return true;
        if (s.count(t)) return false;
        s.insert(t);
        n = t;
    }
    return false; // never
}


// Solution 2 : a very tricky idea similiar to using fast-slow-pointer in 'linked list cycle detection'(141)
int next(int n) {
    int t = 0;
    while (n) {
        t += square(n%10);
        n /= 10;
    }
    return t;
}

bool isHappy_cycle(int n) {
    int slow = n, fast = next(n);
    while (slow != fast) {
        slow = next(slow);
        fast = next(next(fast));
    }
    return slow == 1;
}


int main() {
    cout << isHappy_set(7) << endl;
    cout << isHappy_cycle(7) << endl;
    return 0;
}
