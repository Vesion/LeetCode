#include <iostream>
#include <vector>
#include <string> 
using namespace std;


// Solution 1 : use std::reverse
string reverseString(string s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    return rs;
}


// Solution 2 : implement manually
string reverseString_2(string s) {
    string::size_type i = 0, j = s.size()-1;
    while (i != j) swap(s[i++], s[j--]);
    return s;
}

int main() {
    string s("hello world");
    cout << reverseString(s) << endl;
    cout << reverseString_2(s) << endl;
    return 0;
}
