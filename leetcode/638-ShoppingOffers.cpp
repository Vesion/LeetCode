#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


void operator-=(vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size(); ++i) a[i] -= b[i];
}
void operator+=(vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size(); ++i) a[i] += b[i];
}
bool operator<(const vector<int>& a, int b) {
    for (int i : a) if (i < b) return true;
    return false;
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
        if (needs < 0) return INT_MAX;
        // if buy items without using special offers
        int res = inner_product(needs.begin(), needs.end(), price.begin(), cost);
        // if try special offers
        for (const auto& offer : special) {
            if (cost + offer.back() >= res) continue;
            needs -= offer;
            res = min(res, shoppingOffers(price, special, needs, cost+offer.back()));
            needs += offer;
        }
        return res;
    }
};

int main() {

}
