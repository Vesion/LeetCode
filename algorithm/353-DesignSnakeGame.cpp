#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
#include <unordered_set> 
using namespace std;

class SnakeGame {
private:
    using point = pair<int,int>;
    queue<point> q;
    int score;

    int m, n;
    vector<point> foods;
    unordered_set<int> body; 
public:
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        m = height, n = width;
        foods = food;
        score = 0;
        q.push({0, 0});
        body.insert(0);
    }
    
    int move(string direction) {
        auto head = q.back();
        if (direction == "U") head.first--;
        else if (direction == "L") head.second--;
        else if (direction == "R") head.second++;
        else if (direction == "D") head.first++;
        if (head.first < 0 || head.first >= m || head.second < 0 || head.second >= n) return -1; // out of border

        if (score < (int)foods.size() && head == foods[score]) {
            ++score;
        }
        else {
            body.erase(q.front().first*n + q.front().second);
            q.pop();
        }

        int head_hash = head.first*n + head.second;
        if (body.count(head_hash)) return -1; // collide with body

        q.push(head);
        body.insert(head_hash);
        return score;
    }
};


int main() {
    return 0;
}
