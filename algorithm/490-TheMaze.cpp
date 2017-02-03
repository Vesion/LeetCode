#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : BFS
class Solution_1 {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty()) return false;
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i, nj = j;
                while (ni >= 0 && ni < m && nj >= 0 && nj < n && maze[ni][nj] == 0) ni += go[d][0], nj += go[d][1];
                ni -= go[d][0], nj -= go[d][1];
                if (visited[ni][nj]) continue;
                if (ni == destination[0] && nj == destination[1]) return true;
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
        return false;
    }
};


// Solution 2 : DFS
class Solution {
public:
    int m, n;
    int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty()) return false;
        m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[start[0]][start[1]] = true;
        return dfs(maze, start, destination, visited);
    }

    bool dfs(vector<vector<int>>& maze, vector<int> start, vector<int>& destination, vector<vector<bool>>& visited) {
        if (start == destination) return true;
        for (int d = 0; d < 4; ++d) {
            int ni = start[0], nj = start[1];
            while (ni >= 0 && ni < m && nj >= 0 && nj < n && maze[ni][nj] == 0) ni += go[d][0], nj += go[d][1];
            ni -= go[d][0], nj -= go[d][1];
            if (visited[ni][nj]) continue;
            visited[ni][nj] = true;
            if (dfs(maze, {ni,nj}, destination, visited)) return true;
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<vector<int>> maze = { { 0,0,1,0,0 },{ 0,0,0,0,0 },{ 0,0,0,1,0 },{ 1,1,0,1,1 },{ 0,0,0,0,0 } };
    vector<int> start = { 0,4 };
    vector<int> des = { 4,4 };
    cout << s.hasPath(maze, start, des) << endl;
    return 0;
}

