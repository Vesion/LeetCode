#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<vector<int>> op(N);
    vector<vector<int>> nums(N);
    unordered_map<char, int> m;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        int j = 0;
        while (j < (int)s.size()) {
            if (s[j] >= '0' && s[j] <= '9') {
                int num = s[j++] - '0';
                while (j < (int)s.size() && s[j] >= '0' && s[j] <= '9') {
                    num = num * 10 + s[j++] - '0';
                }
                nums[i].push_back(num);
            }
            else if (s[j] >= 'A' && s[j] <= 'Z') {
                m[s[j]] = -1;
                nums[i].push_back('A'-s[j]-1);
                ++j;
            } else {
                if (s[j+1] == '=') {
                    op[i].push_back(1);
                    j += 2;
                } else {
                    op[i].push_back(0);
                    ++j;
                }
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        bool yes = true;
        for (int i = 0; i < (int)m.size(); ++i) {
            char c; int n;
            cin >> c >> n;
            m[c] = n;
        }
        for (int i = 0; i < N; ++i) {
            vector<int> cnums = nums[i];
            for (int j = 0; j < (int)op[i].size(); ++j) {
                if (cnums[j] < 0) cnums[j] = m[(char)(-cnums[j]-1+'A')];
                if (cnums[j+1] < 0) cnums[j+1] = m[(char)(-cnums[j+1]-1+'A')];
                if (op[i][j] == 0) {
                    if (cnums[j] >= cnums[j+1]) {
                        yes = false;
                        break;
                    }
                } else {
                    if (cnums[j] > cnums[j+1]) {
                        yes = false;
                        break;
                    }
                }
            }
        }
        if (yes) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

