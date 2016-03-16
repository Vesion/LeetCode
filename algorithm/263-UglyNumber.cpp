#include <iostream>
using namespace std;

// Solution 1 : check 2, 3, 5 factor
bool isUgly(int num) {
    if (num < 1) return false;
    while (num != 1) {
        if (!(num%2)) num /= 2;
        else if (!(num%3)) num /= 3;
        else if (!(num%5)) num /= 5;
        else return false; 
    }
    return true;
}


// Solution 1 v2 : another style
bool isUgly_v2(int num) {
    for (int i=2; i<6 && num; i++)
        while (num % i == 0)
            num /= i;
    return num == 1;
}

int main() {
    cout << isUgly(14) << endl;
    cout << isUgly_v2(-123) << endl;
    return 0;
}
