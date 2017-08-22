#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <regex> 
using namespace std;


// Solution 1 : straight forward
class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.find('.') != string::npos && isIPv4(IP)) return "IPv4";
        if (IP.find(':') != string::npos && isIPv6(IP)) return "IPv6";
        return "Neither";
    }

    bool isIPv4(string& s) {
        auto segs = split(s, '.');
        if (segs.size() != 4) return false;
        for (string& seg : segs) {
            int num = 0;
            if (seg.empty() || seg.size() > 3 || (seg.size() > 1 && seg[0] == '0')) return false;
            for (int i = 0; i < (int)seg.size(); ++i) {
                if (isdigit(seg[i])) num = num*10 + seg[i]-'0';
                else return false;
            }
            if (num > 255) return false;
        }
        return true;
    }

    bool isIPv6(string& s) {
        auto segs = split(s, ':');
        if (segs.size() != 8) return false;
        for (string& seg : segs) {
            int num = 0;
            if (seg.empty() || seg.size() > 4) return false;
            for (int i = 0; i < (int)seg.size(); ++i) {
                if (isdigit(seg[i])) num = num*16 + seg[i]-'0';
                else if (isalpha(seg[i])) {
                    char c = tolower(seg[i]);
                    if (c > 'f') return false;
                    num = num*16 + c-'a'+10;
                }
                else return false;
            }
            if (num > 65535) return false;
        }
        return true;
    }

    vector<string> split(string& s, char c) {
        vector<string> res;
        int i = 0, n = s.size();;
        for (int j = 0; j <= n; ++j) {
            if (j == n || s[j] == c) {
                res.push_back(s.substr(i, j-i));
                i = j+1;
            }
        }
        return res;
    }
};


// Solution 2 : regex
class Solution_2 {
public:
    string validIPAddress(string IP) {
        regex ipv4("^([1-9]\\d{0,2}|0)(?:\\.([1-9]\\d{0,2}|0)){3}$");
        regex ipv6("^([0-9a-fA-F]{1,4})(\\:[0-9a-fA-F]{1,4}){7}$");
        
        smatch m;
        if (regex_match(IP, m, ipv4)) {
            for (auto& e: m) {
                if (stoi(e) > 255) return "Neither"; 
            }
            return "IPv4";
        } else if (regex_match(IP, m, ipv6)) return "IPv6";
        return "Neither";
    }
};


int main() {
    Solution s;
    cout << s.validIPAddress("111111111111111111111111.1.1.1") <<endl;
    //cout << s.validIPAddress("20EE:Ffff:85a3:0:0:8A2E:0370:7334") <<endl;
    return 0;
}
