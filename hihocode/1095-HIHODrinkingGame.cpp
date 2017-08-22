#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


const int MAX = 100005;

int N, K;
int d[MAX];

bool HoWin(int T) {
    int sHi = 0, sHo = 0;
    int rest = 0;
    for (int i = 0; i < N; ++i) {
        rest += T;
        if (rest <= d[i]) {
            sHi++;
            rest = 0;
        } else {
            sHo++;
            rest -= d[i];
        }
    }
    return sHo > sHi;
}


int main() {
    ios::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> d[i];

    int left = 0, right = K;
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (HoWin(mid)) right = mid-1;
        else left = mid+1;
    }
    cout << left << endl;
    
    return 0;
}
