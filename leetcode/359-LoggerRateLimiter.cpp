#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Logger {
public:
    unordered_map<string, int> m;

    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = m.find(message);
        if (it == m.end()) {
            m[message] = timestamp;
            return true;
        }
        if (timestamp < it->second + 10) return false;
        it->second = timestamp;
        return true;
    }
};


int main() {
    return 0;
}
