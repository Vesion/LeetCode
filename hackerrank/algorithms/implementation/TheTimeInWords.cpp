#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

string num2word[] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
        "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half"
};
int h, m;

string solve() {
    if (m == 0) return num2word[h]+" o' clock";
    else if (m == 1) return "one minute past "+num2word[h];
    else if (m == 15) return "quarter past "+num2word[h];
    else if (m < 30) return num2word[m]+" minutes past "+num2word[h];
    else if (m == 30) return "half past "+num2word[h];
    else if (m == 45) return "quarter to "+num2word[h+1];
    else if (m == 59) return "one minute to "+num2word[h+1];
    else return num2word[60-m]+" minutes to "+num2word[h+1];
}

int main() {
    cin >> h >> m;
    cout << solve() << endl;
    return 0;
}
