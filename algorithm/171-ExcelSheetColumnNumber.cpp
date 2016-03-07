#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
ll titleToNumber(string s) {
    ll result = 0;
    for (auto & c : s) { result = result*26 + (c-'A'+1); } 
    return result;
}

int main() {
    cout << titleToNumber("AA") << endl;
    return 0;
}
