#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

struct Snack {
    double price;
    int need;
};

void dfs(vector<Snack>& snack, int start, int& result, int count, int need, double price) {
    if (count > 3) return;
    if (fmod(price, 5) == 0)
        result = max(result, need);
    for (int i = start; i < snack.size(); ++i) {
        dfs(snack, i+1, result, count+1, need+snack[i].need, price+snack[i].price);
    }
}


bool Comp(Snack s1, Snack s2) {
    return s1.need > s2.need;
}

int main() {
    ifstream cin("in.txt");
    int cases;
    cin >> cases;
    while (cases--) {
        int N;
        cin >> N;
        vector<Snack> snack(N);
        for (int i = 0; i < N; ++i)
            cin >> snack[i].price >> snack[i].need;

        // solve
        sort(snack.begin(), snack.end(), Comp);
        int result = 0;
        dfs(snack, 0, result, 0, 0, 0.0);
        cout << result << endl;
    }
    return 0;
}
