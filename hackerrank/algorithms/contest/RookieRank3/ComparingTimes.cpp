#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

int main() {
    int q; scanf("%d", &q); 
    while (q--) {
        int h, m; char a[5];
        int t1 = 0;
        scanf("%d:%d%s", &h, &m, a);
        h %= 12;
        if (a[0] == 'P') h += 12;
        t1 = h*60+m;
        int t2 = 0;
        scanf("%d:%d%s", &h, &m, a);
        h %= 12;
        if (a[0] == 'P') h += 12;
        t2 = h*60+m;
        if (t1 < t2) printf("First\n");
        else printf("Second\n");
    }
    return 0;
}
