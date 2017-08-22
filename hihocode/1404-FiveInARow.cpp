#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 20;
int N = 15;
char grid[MAX][MAX];

int main() {
    int cases; cin >> cases; 
    while (cases--) {
        for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) cin >> grid[i][j];
        int res = 0;

        int col[MAX], dig[MAX], anti_dig[MAX];
        for (int i = 1; i <= N; ++i) {
            int row = 0;
            for (int j = 1; j <= N; ++j) {
                if (grid[i][j] == grid[i][j-1]) {
                    if (++row == 5) {
                        if (grid[i][j] == 'B') res |= 1;
                        else if (grid[i][j] == 'W') res |= 2;
                    }
                } else row = 1;

                if (grid[i][j] == grid[i-1][j]) {
                    if (++col[j] == 5) {
                        if (grid[i][j] == 'B') res |= 1;
                        else if (grid[i][j] == 'W') res |= 2;
                    }
                } else col[j] = 1;

                if (grid[i][j] == grid[i-1][j+1]) {
                    if ((dig[j] = dig[j+1]+1) == 5) {
                        if (grid[i][j] == 'B') res |= 1;
                        else if (grid[i][j] == 'W') res |= 2;
                    }
                } else dig[j] = 1;
            }
            for (int j = N; j >= 1; --j) {
                if (grid[i][j] == grid[i-1][j-1]) {
                    if ((anti_dig[j] = anti_dig[j-1]+1) == 5) {
                        if (grid[i][j] == 'B') res |= 1;
                        else if (grid[i][j] == 'W') res |= 2;
                    }
                } else anti_dig[j] = 1;
            }
        }

        if (res == 1) cout << "Black" << endl;
        else if (res == 2) cout << "White" << endl;
        else if (res == 3) cout << "Both" << endl;
        else cout << "None" << endl;
    }
    return 0;
}
