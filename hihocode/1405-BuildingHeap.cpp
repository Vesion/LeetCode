#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 105;
const int INF = 10000000;
int a[MAX];
int N;

void build(int start, int end) {
    if (start >= end) return;
    int minv = INF, mini = start;;
    for (int i = start; i < end; ++i) {
        if (a[i] < minv) minv = a[i], mini = i;
    }
    cout << minv << " ";
    build(start, mini);
    build(mini+1, end);
}

int main() {
    cin >> N;   
    for (int i = 0; i < N; ++i) cin >> a[i];
    build(0, N); cout << endl;
    return 0;
}
