#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map> 
using namespace std;

const int MAX = 100005;
unordered_map<string, int> id;
int root[MAX];
int n, k;

int findRoot(int i) {
    if (i != root[i]) root[i] = findRoot(root[i]);
    return root[i];
}

void unionSet(int i, int j) {
    int ri = findRoot(i), rj = findRoot(j);
    if (ri != rj) root[ri] = rj;
}

int main() {
    for (int i = 0; i < MAX; ++i) root[i] = i;
    cin >> n;
    while (n--) {
        int op;
        string name1, name2;
        cin >> op >> name1 >> name2;
        if (!id.count(name1)) id[name1] = k++;
        if (!id.count(name2)) id[name2] = k++;
        if (op == 0) {
            unionSet(id[name1], id[name2]);
        } else {
            if (findRoot(id[name1]) == findRoot(id[name2])) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}
