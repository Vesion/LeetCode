#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    int la = a.size(), lb = b.size();
    if (la < lb)
        return addBinary(b, a);
    string result(la+1, '0');
    int carry = 0;
    int i = la-1, j = lb-1;
    for (; j >= 0; --i, --j) {
        int na = a[i] - '0', nb = b[j] - '0';
        int sum = na + nb + carry;
        result[i+1] = (sum % 2) + '0';
        carry = sum / 2;
    }
    while (i >= 0) {
        int na = a[i] - '0';
        int sum = na + carry;
        result[i+1] = (sum % 2) + '0';
        carry = sum / 2;
        i--;
    }
    if (carry)
        result[0] = '1';
    if (result[0] == '0')
        result.erase(result.begin());
    return result;
}

int main() {
    cout << addBinary(string("10"), string("10")) << endl;
    return 0;
}
