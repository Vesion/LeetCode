#include <iostream>
#include <vector>
#include <string>
using namespace std;

string multiply(string num1, string num2) {
    if (num1.empty() || num2.empty())
        return "";
    if (num1.length() < num2.length())
        return multiply(num2, num1); // ensure num1.length >= num2.length

    int ln1 = num1.length(), ln2 = num2.length();
    int ln = ln1 + ln2;
    vector<int> result(ln, 0);

    for (int i = ln2-1; i >= 0; --i) {
        int n2 = num2[i] - '0';
        for (int j = ln1-1; j >= 0; --j) {
            int n1 = num1[j] - '0';
            result[i + j + 1] += n1 * n2;
        }
    }

    for (int i = ln-1; i > 0; --i) {
        int r = result[i];
        result[i] = r % 10;
        result[i-1] += r / 10;
    }

    int i = 0;
    while (result[i] == 0) ++i; // ignore prefix 0s
    string sresult = "";
    for (; i < ln; ++i) {
        sresult += (char(result[i] + '0'));
    }

    return sresult.empty() ? "0" : sresult; // for '0' * '0'
}

int main() {
    cout << multiply("0", "0") << endl;
    return 0; 
}
