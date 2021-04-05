#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Leaderboard {
public:
    using Board = multiset<int>;
    Board board;
    unordered_map<int, Board::iterator> player;

    Leaderboard() {}

    void addScore(int playerId, int score) {
        auto it = player.find(playerId);
        if (it != player.end()) {
            score += *it->second;
            board.erase(it->second);
        }
        player[playerId] = board.insert(score);
    }

    int top(int K) {
        int s = 0;
        for (auto it = board.rbegin(); it != board.rend() && K > 0; ++it, --K) {
            s += *it;
        }
        return s;
    }

    void reset(int playerId) {
        auto it = player.find(playerId);
        if (it != player.end()) {
            board.erase(it->second);
            player.erase(playerId);
        }
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

int main() {

}
