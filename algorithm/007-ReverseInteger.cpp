#include <iostream>
#include <vector>
#include <string>
using namespace std;

int reverse(int x) {
	int y = 0;
	int n;
	while (x != 0){
		n = x % 10;
		//Checking the over/underflow.
		//Actually, it should be y>(intmax-n)/10, but n/10 is 0, so omit it.
		//if (y > (INT_MAX-n) / 10 || y < (INT_MIN-n) / 10){
		if (y > INT_MAX / 10 || y < INT_MIN / 10){
			return 0;
		}
		y = y * 10 + n;
		x /= 10;
	}
	return y;
}

int main() {
	cout << reverse(222222) << endl;
	int a;
	cin >> a;
	return 0;
}
