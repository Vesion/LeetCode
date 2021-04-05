#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class SnakeGame {
    deque<pair<int,int>> snake;
    int m, n;
    queue<vector<int>> foods;

    pair<int,int> go(string d) {
        if (d == "U") return {-1, 0};
        if (d == "L") return {0, -1};
        if (d == "R") return {0, 1};
        return {1, 0};
    }

public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m = height, n = width;
        for (const auto& f : food) foods.push(f);
        snake.push_back({0,0});
    }

    int move(string direction) {
        auto [di, dj] = go(direction);
        auto [i, j] = snake.front();
        int ni = i+di, nj = j+dj;
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) return -1;
        if (!foods.empty() && ni == foods.front()[0] && nj == foods.front()[1]) {
            foods.pop();
        } else {
            snake.pop_back();
        }
        // NOTE: must check self-collision after pop tail out
        // can use a hash table to optimize this for-loop out
        for (const auto& p : snake) if (ni == p.first && nj == p.second) return -1;
        snake.push_front({ni, nj});
        return snake.size()-1;
    }
};


int main() {
    return 0;
}
