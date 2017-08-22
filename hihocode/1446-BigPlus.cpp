#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 512;
char maxtrix[MAX][MAX];
int bottom[MAX][MAX];

int main() {
    int N;
    cin >> N;    
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> maxtrix[i][j];

    for (int j = 0; j < N; ++j) {
        for (int i = N-1; i >= 0; --i) {
            if (maxtrix[i][j] == '1') bottom[i][j] = i == N-1 ? 1 : bottom[i+1][j]+1;
        }
    }

    int res = 0;
    vector<int> top(N, 0);
    for (int i = 0; i < N; ++i) {
        vector<int> left(N, 0), right(N, 0);
        for (int j = 0; j < N; ++j) {
            if (maxtrix[i][j] == '1') {
                top[j] = i == 0 ? 1 : top[j]+1;
                left[j] = j == 0 ? 1 : left[j-1]+1;
            }
        }
        for (int j = N-1; j >= 0; --j) {
            if (maxtrix[i][j] == '1') right[j] = j == N-1 ? 1 : right[j+1]+1;
            int h = min(bottom[i][j], top[j]);
            int w = min(left[j], right[j]);
            res = max(res, min(h, w)-1);
        }
    }

    cout << res << endl;
    return 0;
}
