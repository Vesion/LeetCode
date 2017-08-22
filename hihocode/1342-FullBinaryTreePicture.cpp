#include<stdio.h>  
#include<math.h>  

// http://blog.csdn.net/octopusflying/article/details/52020931
  
int N, M;  
  
int compute(int x1, int y1, int x2, int y2) {  
    int H = (int) floor(3 * pow(2, N - 2));  
    int count = 0;  
      
    for(int i = 0; i < N; i++) {  
        int X = H - (int) floor(H / pow(2, i));  
        if(X >= x1 && X <= x2) {  
            if(i < N - 1) {  
                int G = (int) ((2 * X + 1 - pow(2, i)) / (pow(2, i) - 1)) + 1;  
                count += (int) pow(2, i);  
                if(y1 > -1 * X) {  
                    count -= (y1 + X - 1) / G + 1;  
                }  
                  
                if(y2 < X) {  
                    count -= (X - y2 - 1) / G + 1;  
                }  
            } else {  
                count += (int) pow(2, i);  
                if(y1 > -1 * X) {  
                    count -= (y1 + X - 1) / 6 * 2 + 1;  
                    if((y1 + X - 1) % 6 >= 4) {  
                        count -= 1;  
                    }  
                }  
                if(y2 < X) {  
                    count -= (X - y2 - 1) / 6 * 2 + 1;  
                    if((X - y2 - 1) % 6 >= 4) {  
                        count -= 1;  
                    }  
                }  
            }     
        }   
    }  
      
    return count;  
}  
  
int main(void) {  
      
    scanf("%d %d", &N, &M);  
      
    for(int i = 0; i < M; i++) {  
        int x1, y1, x2, y2;  
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);  
        printf("%d\n", compute(x1, y1, x2, y2));  
    }  
      
    return 0;  
}  
