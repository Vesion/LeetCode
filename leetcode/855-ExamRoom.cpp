#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class ExamRoom {
public:
    set<int> seats;
    int n;

    ExamRoom(int N) {
        n = N;
    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        int maxd = 0, res = -1;
        for (auto it = seats.begin(); it != seats.end(); ++it) {
            if (it == seats.begin()) continue;
            auto pit = prev(it);
            int d = (*it - *pit)/2;
            if (d > maxd) maxd = d, res = *pit + d;
        }
        if (*seats.begin() >= maxd) maxd = *seats.begin(), res = 0;
        if (n-1-*seats.rbegin() > maxd) maxd = n-1-*seats.rbegin(), res = n-1;
        seats.insert(res);
        return res;
    }

    void leave(int p) {
        seats.erase(p);
    }
};

int main() {

}
