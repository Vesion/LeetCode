#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	if (x < 10)
		return true;

	int len = 0;
	for (int xx = x; xx != 0; xx /= 10)
		++len;

	int part = 0;
	for (int i = 0; i < len / 2; ++i) {
		part = part * 10 + x % 10;
		x /= 10;
	}
	if (len & 1)
		x /= 10;
	if (part == x)
		return true;

	return false;
}

int main() {
	cout << isPalindrome(11) << endl;
	int a;
	cin >> a;
	return 0;
}