#include <iostream>
using namespace std;


// simple Game Theory, avoid the death number 4
bool canWinNim(int n) {
    return n % 4;
}

int main() {
    cout << canWinNim(2) << endl;
    return 0;
}
