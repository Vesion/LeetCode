#include <iostream>
#include <vector>
#include <string>
using namespace std;

string format(vector<string>& words, int left, int right, int len, int maxWidth) {
    string line = "";
    int wordNum = right - left + 1;
    int whites = maxWidth - len; 
    if (wordNum == 1) { // this line has only one word, should be left-justified
        line += words[left];
        while(whites--) line += " ";
    } else { // whitespaces should be distributed evenly, at least left-evenly
        int slots = wordNum - 1;
        int mod = whites % slots;
        int slotwhites = whites / slots;
        for (int i = left; i < right; ++i) {
            line += words[i];
            for (int j = 0; j < slotwhites; ++j) line += " ";
            if (mod-- > 0) line += " ";
        }
        line += words[right];
    }
    return line;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    if (words.empty())
        return result;
    int len = 0;
    int left = 0, right = 0;
    for (; right < words.size(); ++right) {
        if (len + words[right].size() + (right - left) > maxWidth) {
            result.push_back(format(words, left, right-1, len, maxWidth));
            left = right;
            len = 0;
        }
        len += words[right].size();

        if (right == words.size()-1) { // the last line
            string lastline = "";
            for (int i  = left; i <= right; ++i) {
                lastline += (words[i] + " ");
            }
            lastline.erase(lastline.end()-1);
            while (lastline.size() < maxWidth) lastline += " ";
            result.push_back(lastline);
        }
    }
    return result;
}

int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    //vector<string> words = {""};
    for (auto s : fullJustify(words, 16)) {
        cout << s << endl;
    }
    return 0;
}
