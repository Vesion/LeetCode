#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 4, 5};
    make_heap(v.begin(), v.end(), [](int a, int b) { return a < b; });

    cout << v.front();
    pop_heap(v.begin(), v.end()); v.pop_back();
    cout << v.front();
    pop_heap(v.begin(), v.end()); v.pop_back();
    cout << v.front();
    pop_heap(v.begin(), v.end()); v.pop_back();
    cout << v.front();
    pop_heap(v.begin(), v.end()); v.pop_back();
    return 0;
}
