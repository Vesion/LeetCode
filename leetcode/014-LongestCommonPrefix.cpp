#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty())
		return "";
	if (strs.size() == 1)
		return strs[0];
	string result = "";
	int k = 0;
	while (true) {
		for (int i = 1; i < strs.size(); ++i) {
			if (k == strs[i].size() || strs[i][k] != strs[i-1][k])
				return result;
		}
		result += strs[0][k];
		++k;
	}
	return result;
}

int main() {
	vector<string> s;
	s.push_back("123");
	s.push_back("123");
	s.push_back("123");
	s.push_back("123");
	s.push_back("123");
	cout << longestCommonPrefix(s) << endl;
	system("pause");
	return 0;
}