#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : BFS
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty()) return false;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // dist[i][j] maintain the shortest distance from start to (i,j)
        queue<pair<int,int>> q;
        int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        q.push({start[0]*n + start[1], 0});
        dist[start[0]][start[1]] = 0;
        while (!q.empty()) {
            int i = q.front().first/n, j = q.front().first%n;
            int t = q.front().second;
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i, nj = j;
                int s = 0;
                while (ni >= 0 && ni < m && nj >= 0 && nj < n && maze[ni][nj] == 0) {
                    ni += go[d][0]; nj += go[d][1]; ++s;
                }
                ni -= go[d][0]; nj -= go[d][1]; --s;
                if (t+s >= dist[ni][nj]) continue; // if this is a longer path, no need to move on
                else {
                    dist[ni][nj] = t+s;
                    if (ni != destination[0] || nj != destination[1]) q.push({ni*n + nj, t+s});
                }
            }
        }
        return dist[destination[0]][destination[1]] == INT_MAX ? -1 : dist[destination[0]][destination[1]];
    }
};


// Solution 2 : DFS


int main() {
    Solution s;
    vector<vector<int>> maze = { { 0,0,1,0,0 },{ 0,0,0,0,0 },{ 0,0,0,1,0 },{ 1,1,0,1,1 },{ 0,0,0,0,0 } };
    vector<int> start = { 0,4 };
    vector<int> destination = { 4,4 };
    cout << s.shortestDistance(maze, start, destination) << endl;
    return 0;
}
