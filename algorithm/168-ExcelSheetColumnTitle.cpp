#include <iostream>
#include <string>
using namespace std;

// corner case : 26's times, so use (n-1)%26+'A', rather than n%26-1+'A'
string convertToTitle(int n) {
    string result;
    while (n) {
        result = char((n-1)%26 + 'A') + result;
        n = (n-1) / 26;
    }
    return result;
}

int main() {
    cout << convertToTitle(26) << endl;
    return 0;
}
