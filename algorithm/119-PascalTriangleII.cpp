#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> row;
    if (rowIndex < 0) return row;
    row.push_back(1);
    for (int i = 1; i <= rowIndex; ++i) {
        row.resize(i);
        for (int j = i-1; j > 0; --j)
            row[j] = row[j-1] + row[j];
        row.push_back(1);
    }
    return row;
}

int main() {
    for (auto i : getRow(4))
        cout << i << " ";
    cout << endl;
    return 0;
}

