#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Excel {
private:
    vector<vector<int>> e;
    vector<vector<vector<string>>> f;
    int m, n;

public:
    Excel(int H, char W) {
        m = H, n = W-'A'+1;
        e.resize(m+1, vector<int>(n+1, 0));
        f.resize(m+1, vector<vector<string>>(n+1, vector<string>()));
    }
    
    void set(int r, char c, int v) {
        int row = r, col = c-'A'+1;
        e[row][col] = v;
        f[row][col].clear();
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!f[i][j].empty()) {
                    sum(i, 'A'+j-1, f[i][j]);
                }
            }
        }
    }
    
    int get(int r, char c) {
        int row = r, col = c-'A'+1;
        return e[row][col];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int row = r, col = c-'A'+1;
        e[row][col] = 0;
        f[row][col] = strs;
        for (string& s : strs) {
            if (s.find(':') != string::npos) {
                int si = 0, ei = 0, sj = 0, ej = 0;
                int k = 0;
                sj = s[k++]-'A'+1;
                while (s[k] != ':') si = si*10+s[k++]-'0';
                ++k;
                ej = s[k++]-'A'+1;
                while (k < (int)s.size()) ei = ei*10+s[k++]-'0';
                for (int i = si; i <= ei; ++i) {
                    for (int j = sj; j <= ej; ++j) {
                        if (e[i][j]) {
                            e[row][col] += e[i][j];
                        }
                    }
                }
            } else e[row][col] += e[s[1]-'0'][s[0]-'A'+1];
        }
        return e[row][col];
    }

    void print() {
        for (auto& i : e) {
            for (auto& j : i) { cout << j << " "; }
            cout << endl;
        }
        cout << endl;
    }
};


int main() {
    Excel e(26, 'Z');
    e.set(1, 'A', 1);
    e.set(1, 'I', 1);
    e.set(7, 'D', 3);
    e.sum(10, 'G', {"A1:D7", "D1:F10", "D3:I8", "I1:I9"});
    e.print();
    return 0;
}
