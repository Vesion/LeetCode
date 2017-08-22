#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
int dpf[105][1005], dpm[105][1005];  
unsigned long long fidx[105][1005][2];  
unsigned long long midx[105][1005][2];  

int main() {  
    int n, male, female, b;  
    while(~scanf("%d %d %d %d", &n, &male, &female, &b)) {  
        memset(dpf, -1, sizeof dpf);  
        memset(dpm, -1, sizeof dpm);  
        memset(fidx, 0, sizeof fidx);  
        memset(midx, 0, sizeof midx);  
        dpf[0][0] = dpm[0][0] = 0;  
        int cntm = 0, cntf = 0, sum = 0;  
        for(int i = 1; i <= n; i++) {  
            char str[2];  
            int v, c;  
            scanf("%s %d %d", str, &v, &c);  
            sum += c;  
            sum = min(sum, b);  
            if(str[0] == 'F') {  
                cntf++;  
                cntf = min(cntf, female);  
                for(int j = cntf; j >= 1; j--) {
                    for(int k = sum; k >= c; k--){  
                        if(dpf[j - 1][k - c] < 0) continue;  
                        if(dpf[j - 1][k - c] + v > dpf[j][k]) {  
                            dpf[j][k] = dpf[j - 1][k - c] + v;  
                            fidx[j][k][0] = fidx[j - 1][k - c][0], fidx[j][k][1] = fidx[j - 1][k - c][1];  
                            if(i - 1 < 50) fidx[j][k][0] |= 1LL << (i - 1);  
                            else fidx[j][k][1] |= 1LL << (i - 1 - 50);  
                        }  
                    }  
                }  
            }  
            else {  
                cntm++;  
                cntm = min(cntm, male);  
                for(int j = cntm; j >= 1; j--) {
                    for(int k = sum; k >= c; k--){  
                        if(dpm[j - 1][k - c] < 0) continue;  
                        if(dpm[j - 1][k - c] + v > dpm[j][k]) {  
                            dpm[j][k] = dpm[j - 1][k - c] + v;  
                            midx[j][k][0] = midx[j - 1][k - c][0], midx[j][k][1] = midx[j - 1][k - c][1];  
                            if(i - 1< 50) midx[j][k][0] |= 1LL << (i - 1);  
                            else midx[j][k][1] |= 1LL << (i - 1 - 50);  
                        }  
                    }  
                }  
            }  
        }  
        int ansv = -1, ansc = 0;  
        unsigned long long idx[2] = {0};  
        for(int i = 0; i <= b; i++) {//男女匹配，选取最符合题意的组合  
           if(dpf[female][i] == -1) continue;  
            for(int j = 0; j <= b - i; j++) {  
                if(dpm[male][j] == -1) continue;  
                if(dpf[female][i] + dpm[male][j] > ansv) {  
                    ansv = dpf[female][i] + dpm[male][j];  
                    ansc = i + j;  
                    idx[0] = fidx[female][i][0] | midx[male][j][0];  
                    idx[1] = fidx[female][i][1] | midx[male][j][1];  
                }  
                else if(dpf[female][i] + dpm[male][j] == ansv && ansc > i + j) {  
                    ansc = i + j;  
                    idx[0] = fidx[female][i][0] | midx[male][j][0];  
                    idx[1] = fidx[female][i][1] | midx[male][j][1];  
                }  
                else if(dpf[female][i] + dpm[male][j] == ansv && ansc == i + j) {  
                    int idx0 = fidx[female][i][0] | midx[male][j][0];  
                    int idx1 = fidx[female][i][1] | midx[male][j][1];  
                    if(idx[0] > idx0) {  
                        idx[0] = idx0, idx[1] = idx1;  
                    }  
                    else if(idx[0] == idx[0] && idx[1] > idx1) {  
                        idx[0] = idx0, idx[1] = idx1;  
                    }  
                }  
            }  
        }  
        printf("%d %d\n", ansv, ansc);  
        bool flag = false;  
        for(int i = 1; i <= 50; i++) {  
            if(idx[0] & 1) {  
                if(flag) printf(" ");  
                flag = true;  
                printf("%d", i);  
            }  
            idx[0] >>= 1;  
        }  
        for(int i = 51; i <= 100; i++) {  
            if(idx[1] & 1) {  
                if(flag) printf(" ");  
                flag = true;  
                printf("%d", i);  
            }  
            idx[1] >>= 1;  
        }  
        putchar('\n');  
    }  

    return 0;
}  
