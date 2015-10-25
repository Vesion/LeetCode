#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.size() < 3)
		return result;
	sort(nums.begin(), nums.end());
	const int target = 0;
	vector<int>::iterator last = nums.end();

	for (vector<int>::iterator i = nums.begin(); i < last - 2; ++i) {
		if (i > nums.begin() && *i == *(i - 1))
			continue;

		vector<int>::iterator j = i + 1;
		vector<int>::iterator k = last - 1;
		while (j < k) {
			if (*i + *j + *k < target) {
				++j;
				while (j < k && *j == *(j - 1)) ++j;
			}
			else if (*i + *j + *k > target) {
				--k;
				while (j < k && *k == *(k + 1)) --k;
			}
			else {
				result.push_back({ *i, *j, *k });
				++j;
				--k;
				while (j < k && *j == *(j - 1)) ++j;
				while (j < k && *k == *(k + 1)) --k;
			}
		}
	}

	return result;
}

int main() {
	vector<int> num({ 3, -3, -1, -6, 6, -1, -10, -2, -8, -4, 6, 2, 0, 9, -3, -7, 9, -10, -4, 5, 2, -10, -2, -9});
	vector<vector<int>> r = threeSum(num);
	for (int i = 0; i < r.size(); ++i) {
		for (int j = 0; j < 3; ++j)
			cout << r[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}