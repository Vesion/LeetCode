#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int n = fonts.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (fit(text, w, h, fonts[mid], fontInfo)) l = mid+1;
            else r = mid;
        }
        return r == 0 ? -1 : fonts[r-1];
    }

    using ll = long long;
    bool fit(const string& text, int w, int h, int s, FontInfo& info) {
        ll width = 0;
        for (char c : text) width += info.getWidth(s, c);
        ll height = info.getHeight(s);
        return width <= w && height <= h;
    }
};

int main() {

}
