#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <list> 
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

int N, M;
list<string> cache;
unordered_map<string, list<string>::iterator> m;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M; 
    string url;
    while (N--) {
        cin >> url;
        if (m.count(url)) {
            cache.splice(cache.begin(), cache, m[url]);
            m[url] = cache.begin();
            cout << "Cache" << endl;
        } else {
            cache.push_front(url);
            m[url] = cache.begin();
            if ((int)cache.size() > M) {
                m.erase(cache.back());
                cache.pop_back();
            }
            cout << "Internet" << endl;
        }
    }
    return 0;
}

