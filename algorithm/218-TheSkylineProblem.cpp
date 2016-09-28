#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
#include <map> 
#include <unordered_map> 
#include <set> 
using namespace std;


// Solution 0 : naive, add building one by one, and check if overlapping, O(n^2) time
// Do not implement here.


// Solution 1 : heap + swipe line, O(nlogn) time
class Solution_sl {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;    
        int n = buildings.size();
        int x = 0, h = 0; // current time, current height
        priority_queue<pair<int, int>> pq; // height, end time; max height heap, if height equals, bigger end time goes first
        int i = 0;
        while (i < n || !pq.empty()) {
            // current time is either the next new start time, or the end time of top building
            if (pq.empty() || (i < n && buildings[i][0] <= pq.top().second)) {
                // the next new building starts before the top one ends
                x = buildings[i][0];
                while (i < n && buildings[i][0] == x) { // go throught all the buildings start at the same time, just push them
                    pq.push({buildings[i][2], buildings[i][1]});
                    ++i;
                }
            } else {
                // current tallest building ends before the next new building's starting time
                x = pq.top().second;
                while (!pq.empty() && (pq.top().second <= x)) pq.pop(); // pop those buildings end before the current one
            }
            h = pq.empty() ? 0 : pq.top().first; // get current tallest building's height
            if (result.empty() || (result.back().second != h))
                result.push_back({x, h});
        }
        return result;
    }
};


// Solution 2 : binary search tree (here is multiset), O(nlogn) time
class Solution_bst {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		multimap<int, int> points; // sort all points in ascending x order, if equal, smaller height first
		for (auto& building : buildings) {
			points.emplace(building[0], building[2]);
			points.emplace(building[1], -building[2]);
		}

		multiset<int> heights = {0}; // maintain heights, the max current height is the last one
		vector<pair<int, int>> result;
		int x = -1, y = 0;
		for (auto& p : points) {
			if ((x >= 0) && (p.first != x) && (result.empty() || (result.rbegin()->second != y)))
				result.emplace_back(x, y);

			if (p.second >= 0) // it is start point
				heights.insert(p.second);

			else // it is end point
				heights.erase(heights.find(-p.second));

			x = p.first;
			y = *heights.rbegin();
		}
		if (!result.empty())
			result.emplace_back(x, 0);
		return result;
	}
};


// Solution 3 : divide and conquer, similar to merge sort, O(nlogn) time
class Solution_dc {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        return getSkyline(buildings, 0, buildings.size()-1);
    }

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            auto r1 = getSkyline(buildings, left, mid);
            auto r2 = getSkyline(buildings, mid+1, right);
            return merge(r1, r2);
        }
        return { {buildings[left][0], buildings[left][2]}, {buildings[left][1], 0} }; // terminate condition, left top point and right bottom point
    }

    vector<pair<int,int>> merge(vector<pair<int,int>> &r1, vector<pair<int,int>> &r2) {
        vector<pair<int,int>> result;
        int m = r1.size(), n = r2.size();
        int h1 = 0,h2 = 0,i = 0,j = 0;
        while(i < m && j < n) {
            int x = 0,h = 0;
            if(r1[i].first < r2[j].first) {
                x = r1[i].first;
                h1 = r1[i].second;
                i++;
            } else if(r1[i].first > r2[j].first) {
                x = r2[j].first;
                h2 = r2[j].second;
                j++;
            } else {
                x = r1[i].first;
                h1 = r1[i].second;
                h2 = r2[j].second;
                i++,j++;
            }
            h = max(h1,h2);
            if(result.size() == 0 || h != result[result.size()-1].second)
               result.push_back(make_pair(x,h));
        }
        while(i < m)
            result.push_back(r1[i++]);
        while(j < n)
            result.push_back(r2[j++]);
        return result;
    }
};




// Solution 4 : segment tree, O(nlogn) time
class Solution_st {
public:
    int tree[20000<<2] = {0};

    void update(int i, int l, int r, int vl, int vr, int v) {
        if (vl == l && vr == r)
            tree[i] = max(tree[i], v);
        else {
            int m = (l + r) / 2;
            if (vl > m) update(i*2+1, m+1, r, vl, vr, v);
            else if (vr <= m) update(i*2, l, m, vl, vr, v);
            else {
                update(i*2, l, m, vl, m, v);
                update(i*2+1, m+1, r, m+1, vr, v);
            }
        }
    }

    int query(int i, int l, int r, int q) {
        if (l == r) return tree[i];
        int m = (l + r) / 2;
        int result = (q <= m ? query(i*2, l, m, q) : query(i*2+1, m+1, r, q));
        return max(result, tree[i]);

    }

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        unordered_map<int, int> line;
        unordered_map<int, int> rline;
        int n = buildings.size();
        set<int> l;
        int top = -2;
        int pre = -1;
        for(int i = 0; i < n; i++) {
            l.insert(buildings[i][0]);
            l.insert(buildings[i][1]);
        }
        set<int>::iterator it;
        for(it = l.begin(); it != l.end(); it++) {
            if(pre != -1 && *it == pre+1) {
                top++;
            }
            else {
                top+=2;
            }
            line[*it] = top;
            rline[top] = *it;
            pre = *it;
        }
        for(int i = 0; i < n; i++) {
            update(1, 0, top, line[buildings[i][0]], line[buildings[i][1]], buildings[i][2]);
        }
        vector<pair<int, int>> res;
        int ph = 0;
        for(int i = 0; i <= top; i++) {
            int h = query(1, 0, top, i);
            if(h != ph) {
                res.push_back(make_pair(h > ph ? rline[i] : rline[i-1], h));
                ph = h;
            }
        }
        if(n > 0) {
            res.push_back(make_pair((rline[top]), 0));
        }
        return res;
    }
};


// Solution 5 : binary indexed tree, similar to segment tree
class Solution_bit {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // TODO
        return {};
    }
};


int main() {
    vector<vector<int>> b = { { 1,2,1 },{ 2147483646,2147483647,2147483647 } };
    Solution_st s;
    auto r = s.getSkyline(b);
    for (auto& e : r) cout << e.first << " " << e.second << endl; cout << endl; 
    return 0;
}
