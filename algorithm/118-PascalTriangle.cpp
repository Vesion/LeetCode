#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    if (numRows <= 0) return result;
    result.push_back(vector<int>({1}));
    numRows--;
    while (numRows--) {
        auto lastline = result.back();
        vector<int> thisline({1});
        for (int i = 0; i < lastline.size()-1; ++i)
            thisline.push_back(lastline[i] + lastline[i+1]);
        thisline.push_back(1);
        result.push_back(thisline);
    }
    return result;
}

int main() {
    for (auto i : generate(5)) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
