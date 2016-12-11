#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class TicTacToe {
private:
    vector<int> rows, cols;
    int diagonal, anti_diagonal, n;

public:
    TicTacToe(int n) {
        this-> n = n;
        rows.resize(n, 0);
        cols.resize(n, 0);
        diagonal = anti_diagonal = 0;
    }
    
    int move(int row, int col, int player) {
        int v = player == 1 ? 1 : -1;
        rows[row] += v;
        cols[col] += v;
        if (row == col) diagonal += v;
        if (row == n-1-col) anti_diagonal += v;
        if (rows[row] == n || cols[col] == n || diagonal == n || anti_diagonal == n) return 1;
        if (rows[row] == -n || cols[col] == -n || diagonal == -n || anti_diagonal == -n) return 2;
        return 0;
    }
};


int main() {
    return 0;
}
