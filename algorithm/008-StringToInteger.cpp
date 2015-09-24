#include <iostream>
#include <vector>
#include <string>
using namespace std;

int myAtoi(string str) {
	if (str.size() == 0)
		return 0;

	int result = 0;
	int i = 0;
	bool op = true;

	while (str[i] == ' ') { ++i; }

	if (str[i] == '-') {
		op = false;
		++i;
	}
	else if (str[i] == '+') {
		op = true;
		++i;
	}

	if (i == str.size() || str[i] < '0' || str[i] > '9')
		return 0;

	while (i < str.size() && (str[i] >= '0' && str[i] <= '9')) {
		if (result > INT_MAX / 10) {
			return (op ? INT_MAX : INT_MIN);
		}
		else if (result == INT_MAX / 10) {
			if (op == true && str[i] > '7')
				return INT_MAX;
			else if (op == false && str[i] > '8')
				return INT_MIN;
		}
		result = result * 10 + (str[i] - '0');
		++i;
	}
	return (op ? result : 0 - result);
}

int main() {
	cout << myAtoi("   +2147483648") << endl;
	int a;
	cin >> a;
	return 0;
}