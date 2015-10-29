#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
	Time: O(n^3)
	Almost time exceeded
*/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	if (nums.size() < 4)
		return result;
	sort(nums.begin(), nums.end());
	auto last = nums.end();
	for (auto i = nums.begin(); i < last - 3; ++i) {
		if (i != nums.begin() && *i == *(i - 1)) continue;
		for (auto j = i + 1; j < last - 2; ++j) {
			if (j != i + 1 && *j == *(j - 1)) continue;
			auto k = j + 1;
			auto l = last - 1;
			while (k < l) {
				int sum = *i + *j + *k + *l;
				if (sum == target) {
					vector<int> v({ *i, *j, *k, *l });
					result.push_back(v);
					++k;
					--l;
					while (k < l && *k == *(k - 1)) ++k;
					while (k < l && *l == *(l + 1)) --l;
				}
				else if (sum < target) {
					++k;
					while (k < l && *k == *(k - 1)) ++k;
				}
				else if (sum > target) {
					--l;
					while (k < l && *l == *(l + 1)) --l;
				}
			}
		}
	}
	return result;
}

/*
	Time: O(n^2)
	Memory: O(n^2)
	first step use map to store sum of any two num, then two loops in nums
*/

/*
	Time: average O(n^2)   worst O(n^4)
	Memory: O(n^2)
	first step use multi-map to store sum of any two nums, then two loops in cache
*/

int main() {
	vector<int> num({ 1 ,0 ,-1 ,0 ,-2 ,2 });
	vector<vector<int>> r = fourSum(num, 0);
	for (int i = 0; i < r.size(); ++i) {
		for (int j = 0; j < 4; ++j)
			cout << r[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}