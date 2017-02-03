#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list> 
#include <numeric> 
using namespace std;

// unordered_set and list both get TLE!
// So, we use array indexing to simulate list.

class PhoneDirectory {
private:
    vector<int> nums;
    vector<bool> used;
    int cur, upper;
    
public:
    PhoneDirectory(int maxNumbers) {
        cur = 0, upper = maxNumbers;
        used.resize(maxNumbers, false);
        nums.resize(maxNumbers);
        iota(nums.begin(), nums.end(), 0);
    }
    
    int get() {
        if (cur == upper) return -1;
        int res = nums[cur++];
        used[res] = true;
        return res;
    }
    
    bool check(int number) {
        return number >= 0 && number < upper && !used[number];
    }
    
    void release(int number) {
        if (number < 0 || number >= upper || !used[number]) return;
        nums[--cur] = number;
        used[number] = false;
    }
};


int main() {
    PhoneDirectory p(1);
    cout << p.check(0) <<endl;
    cout << p.get() <<endl;
    cout << p.check(0) <<endl;
    cout << p.get() <<endl;
    p.release(0);
    cout << p.check(0) <<endl;
    cout << p.get() <<endl;
    cout << p.check(0) <<endl;
    cout << p.get() <<endl;
    return 0;
}
