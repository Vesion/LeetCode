#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string Small[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string Middle[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const string Large[] = {"Hundred", "Thousand", "Million", "Billion"};

void strip(string& s) {
    auto b = s.find_first_not_of(" ");
    auto e = s.find_last_not_of(" ");
    s = s.substr(b, e-b+1);
}

string convert(int num) { // convert a number less than 1000 to words
    string result;
    if (num >= 100) { result += Small[num/100] + " " + Large[0] + " "; num %= 100; }
    if (num < 20) { if (num || result.empty()) result += Small[num];  }
    else { // 100 > num >= 20 
        result += Middle[num/10] + " "; num %= 10; 
        if (num) result += Small[num];
    }
    strip(result);
    return result;
}

string numberToWords(int num) {
    vector<int> chunks;
    while (num) { chunks.push_back(num%1000); num /= 1000; }
    reverse(chunks.begin(), chunks.end());

    string result;
    int n = chunks.size();
    for (int i = 0; i < n; ++i) {
        string r = convert(chunks[i]);
        if (r != "Zero") {
            if (i != n-1) r += " " + Large[n-1-i] + " ";
            result += r;
        }
    }
    if (result.empty()) result = "Zero";
    strip(result);
    return result;
}

int main() {
    cout << numberToWords(100011001) << endl;
    return 0;
}
