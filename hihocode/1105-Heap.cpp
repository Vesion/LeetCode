#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
using namespace std;

const int MAXN = 1e5+5;
int heap[MAXN];
int M;

#define left(i) (i*2+1)
#define right(i) (i*2+2)
#define parent(i) ((i-1)/2)

void shift_down(int i, int n) {
    int max_i = i;
    if (left(i) < n && heap[max_i] < heap[left(i)]) max_i = left(i);
    if (right(i) < n && heap[max_i] < heap[right(i)]) max_i = right(i);
    if (max_i == i) return;
    swap(heap[i], heap[max_i]);
    shift_down(max_i, n);
}

void sift_up(int i) {
    int min_i = i;
    if (i > 0 && heap[parent(i)] < heap[i]) min_i = parent(i);
    if (min_i == i) return;
    swap(heap[i], heap[min_i]);
    sift_up(min_i);
}

void extract_top(int n) {
    swap(heap[0], heap[n-1]);
    shift_down(0, n-1);
}

int main() {
    cin >> M;
    int n = 0;
    while (M--) {
        char op; cin >> op;
        if (op == 'A') {
            cin >> heap[n++];
            sift_up(n-1);
        } else {
            cout << heap[0] << endl;
            extract_top(n--);
        }
    }
    return 0;
}
