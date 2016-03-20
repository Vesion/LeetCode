#include <iostream>
#include <string>
using namespace std;

// dfs + backtracking
string add(string s1, string s2) {
    string result;
    int i = s1.size()-1, j = s2.size()-1, carry = 0;
    while (i >= 0 || j >= 0) {
        int sum = carry + (i>=0 ? s1[i--]-'0' : 0) + (j>=0 ? s2[j--]-'0' : 0);
        result.push_back(sum%10 + '0');
        carry = sum / 10;
    }
    if (carry) result.push_back(carry + '0');
    reverse(result.begin(), result.end());
    return result;
}

bool dfs(string num1, string num2, string num3) {
    if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) return false;
    string sum = add(num1, num2);
    if (sum == num3) return true;
    if (num3.size() <= sum.size() || sum.compare(num3.substr(0, sum.size())) != 0) return false;
    return dfs(num2, sum, num3.substr(sum.size()));
}

bool isAdditiveNumber(string num) {
    int n = num.size();
    if (n < 3) return false;
    for (int i = 1; i <= n/2; ++i) {
        for (int j = 1; j <= (n-i)/2; ++j)
            if (dfs(num.substr(0, i), num.substr(i, j), num.substr(i+j))) return true;
    }
    return false;
}

int main() {
    cout << isAdditiveNumber("199100199") << endl;
    return 0;
}
