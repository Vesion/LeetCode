#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Given a pole with length L, there are N ants on it with position x[i], and direction d[i] (0 for left, 1 for right),
// each ant is walking toward a direction with same speed 1, when any of two ants bump into each other, they will turn around and walk toward the opposite direction.
//
// Problem 1 : If each ant's direction can be either left or right, what is the minimum and maximum time do they spend to walk out away the pole?
//
// Problem 2 : How many times do they bump totally?
//
// Problem 3 : What time does the k-th(count from left and start with 1) ant walk out away the pole?


// Problem 1
vector<int> getMinMaxTime(vector<int>& x, int L) {
    int mint = INT_MIN, maxt = INT_MIN;
    for (int& i : x) {
        mint = max(mint, min(i, L-i));
        maxt = max(maxt, max(i, L-i));
    }
    return {mint, maxt};
}


// Problem 2
int bumpTimes(vector<int>& x, vector<int>& d, int L) { // x and L are useless here
    int n = x.size();
    int left = 0, right = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) ++left;
        else res += left;
    }
    for (int i = n-1; i >= 0; --i) {
        if (d[i] == 1) ++right;
        else res += right;
    }
    return res;
}


// Probelm 3
int timeOfAntIWalkAway(vector<int>& x, vector<int>& d, int L, int k) {
    int n = x.size();
    int left = 0;
    for (int i = 0; i < n; ++i) if (d[i] == 0) ++left;
    if (k <= left) {
        int l = 0;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0) ++l;
            if (l == k) return x[i];
        }
    } else {
        k = n-k+1;
        int r = 0;
        for (int i = n-1; i >= 0; --i) {
            if (d[i] == 1) ++r;
            if (r == k) return L-x[i];
        }
    }
    return 0; // never
}


int main() {
    return 0;
}
