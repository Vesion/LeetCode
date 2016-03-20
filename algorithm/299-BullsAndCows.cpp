#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


// Solution 1 : three passes
string getHint_3passes(string secret, string guess) {
    if (secret.empty()) return "0A0B";
    int n = secret.size();
    int A = 0, B= 0;
    for (int i = 0; i < n; ++i) { // count bulls
        if (secret[i] == guess[i]) {
            ++A;
            secret[i] = guess[i] = ' ';
        }
    }
    int count[10] = {0};
    for (auto & c : secret) if (c != ' ') ++count[c-'0']; // store occurring times of each number
    for (auto & c : guess) // count cows
        if (c != ' ' && count[c-'0']) { ++B; --count[c-'0']; }
    return to_string(A) + "A" + to_string(B) + "B";
}


// Solution 2 : two passes
string getHint_2passes(string secret, string guess) {
    if (secret.empty()) return "0A0B";
    int n = secret.size();
    int A = 0, B = 0;
    int cs[10] = {0}, cg[10] = {0};
    for (int i = 0; i < n; ++i) {
        if (secret[i] == guess[i]) ++A;
        else {
            ++cs[secret[i]-'0'];
            ++cg[guess[i]-'0'];
        }
    }
    for (int i = 0; i < 10; ++i)
        B += min(cs[i], cg[i]);
    return to_string(A) + "A" + to_string(B) + "B";
}


// Solution 3 : one pass
string getHint_1pass(string secret, string guess) {
    if (secret.empty()) return "0A0B";
    int n = secret.size();
    int A = 0, B = 0;
    int count[10] = {0};
    for (int i = 0; i < n; ++i) {
        if (secret[i] == guess[i]) ++A;
        else {
            // here is a little tricky, it means: increment cows when either number from secret was already seen in guest or vice versa.
            // it is actually a producer-and-consumer model
            if (count[secret[i]-'0']++ < 0) ++B; // producer
            if (count[guess[i]-'0']-- > 0) ++B; // consumer
        }
    }
    return to_string(A) + "A" + to_string(B) + "B";
}

int main() {
    cout << getHint_3passes("111343", "012411") << endl;
    cout << getHint_2passes("111343", "012411") << endl;
    cout << getHint_1pass("111343", "012411") << endl;
    return 0;
}
