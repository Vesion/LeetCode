#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    bool find = false;
    int len = 0;
    for (int i = s.size()-1; i >= 0; --i) {
        if (s[i] != ' ') {
            find = true;
            ++len;

        } else if (find == true) {
            return len;
        }
    }
    if (find == false)
        return 0;
    return len;
}

int main() {
    cout << lengthOfLastWord("a aa ");
    return 0;
}
