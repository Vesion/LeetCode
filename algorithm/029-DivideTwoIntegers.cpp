#include <iostream>
using namespace std;

// slow!
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    bool op = (dividend & 0x80000000) ^ (divisor & 0x80000000);

    uint64_t dd = (dividend < 0 ? -(uint64_t)dividend : (uint64_t)dividend);
    uint64_t ds = (divisor < 0 ? -(uint64_t)divisor : (uint64_t)divisor);

    uint64_t sum = 0;
    uint64_t result = 0;
    while (true) {
        if (sum + ds == dd) { // divided completely
            result += 1;
            break;
        }
        if (sum + ds > dd) // cannot be divided completely
            break;
        uint64_t add = ds, i = 1;
        while (sum + add <= dd) {
            sum += add;
            result += i;
            add += add;
            i += i;
        }
    }

    return (op ? -result : result);
}

int main() {
    //cout << divide(INT_MIN, INT_MIN);
    cout << divide(INT_MIN, -1);
    return 0;
}
