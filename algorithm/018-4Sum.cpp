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
	Time: average O(n^2)   worst O(n^4)
	Memory: O(n^2)
	first step use map to store sum of any two num, then two loops in nums
*/
vector<vector<int>> fourSum_map(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4)
        return result;
    sort(nums.begin(), nums.end());
    unordered_map<int, vector<pair<int, int>>> cache;
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            cache[nums[i] + nums[j]].push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            int rest = target - nums[i] - nums[j];
            if (cache.find(rest) == cache.end())
                continue;
            auto &vec = cache[rest];
            for (int k = 0; k < vec.size(); ++k) {
                if (j >= vec[k].first)
                    continue;
                result.push_back({nums[i], nums[j], nums[vec[k].first], nums[vec[k].second]});
            }
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

/*
	Time: O(n^2)
	Memory: O(n^2)
	first step use multi-map to store sum of any two nums, then two loops in cache
    perhaps time exceeded in leetcode
*/
vector<vector<int>> fourSum_multimap(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4)
        return result;
    sort(nums.begin(), nums.end());
    unordered_multimap<int, pair<int, int>> cache;
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j= i + 1; j < nums.size(); ++j) {
            cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
        }
    }
    for (auto i = cache.begin(); i != cache.end(); ++i) {
        int rest = target - i->first;
        auto range = cache.equal_range(rest);
        for (auto j = range.first; j != range.second; ++j) {
            int a = i->second.first;
            int b = i->second.second;
            int c = j->second.first;
            int d = j->second.second;
            if (a != c && a != d && b != c && b != d) {
                vector<int> vec({nums[a], nums[b], nums[c], nums[d]});
                sort(vec.begin(), vec.end());
                result.push_back(vec);
            }
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

int main() {
	vector<int> num({91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245});
	vector<vector<int>> r = fourSum_multimap(num, -236727523);
	for (int i = 0; i < r.size(); ++i) {
		for (int j = 0; j < 4; ++j)
			cout << r[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
