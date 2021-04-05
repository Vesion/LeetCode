#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int row[3] = {}, col[3] = {};
        int di = 0, ad = 0;
        int c = 0;
        for (int i = 0; i < moves.size(); ++i) {
            ++c;
            const auto& m = moves[i];
            if (i&1) {
                --row[m[0]]; --col[m[1]];
                if (m[0] == m[1]) --di;
                if (m[0]+m[1] == 2) --ad;
            } else {
                ++row[m[0]]; ++col[m[1]];
                if (m[0] == m[1]) ++di;
                if (m[0]+m[1] == 2) ++ad;
            }
        }
        bool awin = row[0] == 3 || row[1] == 3 || row[2] == 3 ||
                    col[0] == 3 || col[1] == 3 || col[2] == 3 ||
                    di == 3 || ad == 3;
        if (awin) return "A";
        bool bwin = row[0] == -3 || row[1] == -3 || row[2] == -3 ||
                    col[0] == -3 || col[1] == -3 || col[2] == -3 ||
                    di == -3 || ad == -3;
        if (bwin) return "B";
        if (c == 9) return "Draw";
        return "Pending";
    }
};

int main() {
}
