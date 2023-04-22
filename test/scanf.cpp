#include <iostream>
#include <vector>
using namespace std;

int main() {
    char opt[10];
    int ip[4];
    char ch;
    scanf("%d.%d.%d.%d%c", ip, ip+1, ip+2, ip+3, &ch);
    cout << ch-0 << endl;

    int a;
    scanf("%[^,],%d", opt, &a);
    cout << opt << endl;
    cout << a << endl;
    return 0;
}
