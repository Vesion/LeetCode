#include <iostream> 
using namespace std;

const int MOD = 1000000007;

int table[11] = {0, 1, 2, 3, 4, 5, 6, 9, 12, 16, 20};

int solve(int N) {
    if(N <= 10){
        return table[N];
    }else{
        long long ans = 1;
        while(N % 5 != 4 && N > 10){
            ans = (ans * 3) % MOD;
            N -= 4;
        }
        if(N <= 10){
            ans = (ans * table[N]) % MOD;
        }else{
            int temp = N / 5 + 1;
            for(int i = 0; i < temp; ++i){
                ans = (ans * 4) % MOD;
            }
        }
        return ans;
    }
}


int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cout << i << " " << solve(i) << endl;;
    return 0;
}
