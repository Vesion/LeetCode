#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
private:
    string alnum = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        while (!url2code.count(longUrl)) {
            code = "";
            for (int i = 0; i < 6; ++i) code += alnum[rand()%alnum.size()];
            if (!code2url.count(code)) {
                url2code[longUrl] = code;
                code2url[code] = longUrl;
                break;
            }
        }
        return url2code[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code2url[shortUrl];
    }
};


int main() {
    Solution s;
    string e = s.encode("abcd");
    cout << e << endl;
    cout << s.decode(e) << endl;
    return 0;
}
