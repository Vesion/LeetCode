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
        int val = (player == 1) ? 1 : -1;
        rows[row] += val;
        cols[col] += val;
        diagonal += (row == col) ? val : 0;
        anti_diagonal += (row == n-1-col) ? val : 0;
        if (rows[row] == n || cols[col] == n || diagonal == n || anti_diagonal == n) return 1;
        if (rows[row] == -n || cols[col] == -n || diagonal == -n || anti_diagonal == -n) return 2;
        return 0;
    }
};


int main() {
    return 0;
}
