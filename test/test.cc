#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <array>
#include <sstream>
#include <bitset>
using namespace std;

int main() {
    string w;
    istringstream in("/a/");
    while (getline(in, w, '/')) {
        cout << "-  " << w << endl;
    }
    return 0;
}