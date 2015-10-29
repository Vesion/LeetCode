#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	auto last = nums.end();
	int sum = *(last - 1) + *(last - 2) + *(last - 3);
	for (auto i = nums.begin(); i < last - 2; ++i) {
		if (i > nums.begin() && *i == *(i - 1))
			continue;
		auto j = i + 1;
		auto k = last - 1;
		while (j < k) {
			int tsum = *i + *j + *k;
			if (tsum == target)
				return target;
			if (tsum < target) {
				++j;
				while (j < k && *(j - 1) == *j) ++j;
			}
			else if (tsum > target) {
				--k;
				while (j < k && *(k + 1) == *k) --k;
			}
			if (abs(target - tsum) < abs(target - sum))
				sum = tsum;
		}
	}
	return sum;
}

int main() {
	vector<int> nums({ 1, 1, -1, -1, 3});
	cout << threeSumClosest(nums, 1);
	system("pause");
	return 0;
}