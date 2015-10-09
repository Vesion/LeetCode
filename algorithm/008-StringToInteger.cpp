#include <iostream>
#include <vector>
#include <string>
using namespace std;

int myAtoi(string str) {
	if (str.size() == 0)
		return 0;

	int result = 0;
	int i = 0;
	int op = 1;
    int n = str.size();

	while (str[i] == ' ') { ++i; }

	if (str[i] == '-') {
		op = -1;
		++i;
	}
	else if (str[i] == '+') {
		++i;
	}

    for (; i < n; ++i) {
        if (str[i] < '0' || str[i] > '9')
            break;
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
			return op == 1 ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (str[i] - '0');
    }
    return result * op; 
}

int main() {
	cout << myAtoi("   +2147483648") << endl;
	int a;
	cin >> a;
	return 0;
}
