#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;

inline ll _abs(ll i) {
    return (i < 0 ? -i : i);
}

string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    if (numerator == denominator) return "1";

    string result;
    if ((numerator < 0) ^ (denominator < 0)) result += "-";
    ll a = _abs(numerator);
    ll b = _abs(denominator);


    // interger
    result += to_string(a/b);
    a %= b;
    if (a == 0) return result; // no decimal part, return

    // decimal
    result += '.';
    unordered_map<int, int> m; // key is a, value is result.size(), for recurring
    while (a) {
        a *= 10;
        if (m.find(a) != m.end()) { // recurring occurs
            result.insert(m[a], "(");
            result += ")";
            break;
        }
        result += to_string(a/b);
        m[a] = result.size()-1;
        a %= b;
    }
    return result;
}

int main() {
    int a = 7;
    int b = 12;
    cout << fractionToDecimal(a, b) << endl;
    return 0;
}
