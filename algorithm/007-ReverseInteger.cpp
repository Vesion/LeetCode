#include <iostream>
#include <vector>
#include <string>
using namespace std;

int reverse(int x) {
	const int intmax = 2147483647;
	const int intmin = -intmax - 1;
	int y = 0;
	int n;
	while (x != 0){
		n = x % 10;
		//Checking the over/underflow.
		//Actually, it should be y>(intmax-n)/10, but n/10 is 0, so omit it.
		//if (y > (intmax-n) / 10 || y < (intmin-n) / 10){
		if (y > intmax / 10 || y < intmin / 10){
			return 0;
		}
		y = y * 10 + n;
		x /= 10;
	}
	return y;
}

int main() {
	int n = 2147483648;
	int m = -123;
	cout << reverse(m) << endl;
	int a;
	cin >> a;
	return 0;
}