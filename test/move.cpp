#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a({1, 2, 4});
    vector<int> b = a;
    vector<int> c = std::move(a);
    cout << b.size() << endl;
    cout << c.size() << endl;
    cout << a.size() << endl;
    return 0;
}
