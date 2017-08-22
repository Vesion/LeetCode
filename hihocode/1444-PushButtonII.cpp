#include <iostream> 
using namespace std;

typedef long long LL;
const int MAX = 1001, MOD = 1000000007;
LL C[MAX][MAX], result[MAX];

void init(){
    for(int i = 0; i < MAX; ++i){
        C[i][i + 1] = 0;
        C[i][0] = 1;
    }
    for(int i = 1; i < MAX; ++i){
        for(int j = 1; j < MAX; ++j){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
};

void table(){
    result[0] = result[1] = 1;
    for(int i = 2; i < MAX; ++i){
        result[i] = 0;
        for(int j = 1; j <= i; ++j){
            result[i] = (result[i] + C[i][j] * result[i - j]) % MOD;
        }
    }
}

int main(){
    init();
    table();
    int N;
    cin >> N;
    cout << result[N];
    return 0;
}
