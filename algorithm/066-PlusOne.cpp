#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    vector<int> result(n+1);
    for (int i = n-1; i >= 0; --i)
        result[i+1] = digits[i];
    result[n] += 1;
    int carry = 0;
    for (int i = n; i >= 0; --i) {
        int sum = result[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
    if (result[0] == 0)
        result.erase(result.begin());
    return result;
}

int main() {
    vector<int> digits({89});
    for (auto i : plusOne(digits)) {
        cout << i;
    }
    cout << endl;
    return 0;
}
