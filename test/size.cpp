#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a{1, 2, 4, 4, 5};
    cout << sizeof(vector<int>) << endl;
    cout << sizeof(a) << endl;
    cout << a.size() * sizeof(vector<int>::value_type) << endl;
    return 0;
}
