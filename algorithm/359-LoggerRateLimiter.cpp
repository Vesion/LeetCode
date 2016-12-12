#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Logger {
private:
    unordered_map<string, int> m;
public:
    Logger() { }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!m.count(message) || timestamp - m[message] >= 10) {
            m[message] = timestamp;
            return true;
        }
        return false;
    }
};


int main() {
    return 0;
}
