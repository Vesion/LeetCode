#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

// greedy, similar to 264-UglyNumberII, maintain a ascending sequence of primes' multiples

// Solution 1 : O(n*k)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> pi(m, 0);
        vector<int> nums(n, 0);
        nums[0] = 1;
        for (int i = 1; i < n; ++i) {
            int num = INT_MAX;
            for (int j = 0; j < m; ++j) num = min(num, nums[pi[j]]*primes[j]);
            nums[i] = num;
            for (int j = 0; j < m; ++j) if (num == nums[pi[j]]*primes[j]) pi[j]++;
        }
        return nums[n-1];
    }
};


// Solution 2 : use heap to maintain nexts, O(n*logk)
class Solution_2 {
private:
    struct Num { 
        int id, val, prime; 
        bool operator< (const Num& num) const { return val > num.val; }
    };

public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> nums(n, 0);
        nums[0] = 1;

        priority_queue<Num> pq;
        for (int& prime : primes) pq.push({0, prime, prime});
        for (int i = 1; i < n; ++i) {
            nums[i] = pq.top().val;
            while (!pq.empty() && nums[i] == pq.top().val) {
                auto next = pq.top(); pq.pop();
                pq.push({next.id+1, nums[next.id]*next.prime, next.prime});
            }
        }
        return nums[n-1];
    }
};


int main() {
    return 0;
}
