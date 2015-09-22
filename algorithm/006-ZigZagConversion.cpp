#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getNextIndex(int curr, int row, int numRows, int down) {
	int next = 0;
	if (row == 0 || row == numRows - 1) {
		next = curr + (numRows - 1) * 2;
	}
	else {
		if (down) {
			next = curr + (numRows - row - 1) * 2;
		}
		else {
			next = curr + row * 2;
		}
	}

	return next;
}

string convert1(string s, int numRows) {
	int ssize = s.size();
	if (ssize <= numRows || numRows == 1)
		return s;

	string result;
	int index = 0;

	for (int i = 0; i < numRows; ++i) {
		int down = 1;
		index = i;
		while (index < ssize)
		{
			result += s[index];
			index = getNextIndex(index, i, numRows, down);
			down = 1 - down;
		}
	}

	return result;
}

string convert2(string s, int nRows) {
	//The cases no need to do anything
	if (nRows <= 1 || nRows >= s.size()) return s;

	vector<string> r(nRows);
	int row = 0;
	int step = 1;
	for (int i = 0; i<s.size(); i++) {
		if (row == nRows - 1) step = -1;
		if (row == 0) step = 1;
		//cout << row <<endl;
		r[row] += s[i];
		row += step;
	}

	string result;
	for (int i = 0; i<nRows; i++){
		result += r[i];
	}
	return result;
}

int main() {
	string s("qwertyuiopasdfghjklzxcvbnm");
	cout << convert2(s, 10) << endl;
	int a;
	cin >> a;
	return 0;
}