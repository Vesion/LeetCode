#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        int i = 0, n = code.size();
        return parse(code, n, i) && i == n;
    }

    bool parse(string& code, const int& n, int& i) {
        if (code[i++] != '<') return false;
        string start_tag;
        while (i < n && code[i] != '>') {
            if (!isupper(code[i])) return false;
            start_tag += code[i++];
        }
        ++i;

        while (i < n) {
            if (code[i] == '<' && i+1 < n) {
                if (code[i+1] == '/') { // end tag
                    break;
                } else if (code[i+1] == '!') { // CDATA
                    if (!parse_cdata(code, n, i)) return false;
                } else { // nested tag
                    if (!parse(code, n, i)) return false;
                }
            } else {
                ++i;
            }
        }

        if (code[i++] != '<') return false;
        if (code[i++] != '/') return false;
        string end_tag;
        while (i < n && code[i] != '>') {
            if (!isupper(code[i])) return false;
            end_tag += code[i++];
        }
        ++i;
        return start_tag.size() >= 1 && start_tag.size() <= 9 && start_tag == end_tag;
    }

    bool parse_cdata(string& code, const int& n, int& i) {
        if (code.substr(i, 9) != "<![CDATA[") return false;
        i += 9;
        while (i < n) {
            if (i+2 < n && code[i] == ']' && code[i+1] == ']' && code[i+2] == '>') {
                i += 3;
                return true;
            }
            ++i;
        }
        return false;
    }
};


int main() {
    Solution s;
    cout << s.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>") << endl;
    cout << s.isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>") << endl;
    cout << s.isValid("<A>  <B> </A>   </B>") << endl;
    cout << s.isValid("<DIV>  div tag is not closed  <DIV>") << endl;
    cout << s.isValid("<DIV>  unmatched <  </DIV>") << endl;
    cout << s.isValid("<DIV> closed tags with invalid tag name  <b>123</b> </DIV>") << endl;
    cout << s.isValid("<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>") << endl;
    cout << s.isValid("<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>") << endl;
    cout << s.isValid("<A></A><B></B>") << endl;
    cout << s.isValid("<AAAAAAAAAA></AAAAAAAAAA>") << endl;
    return 0;
}
