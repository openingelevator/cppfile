#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x,
            int y) {
        int square = 1;
        queue<pair<int, int>> que;
        que.push({x, y});
        visited[x][y] = true;
        while (!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();
            int curx = cur.first;
            int cury = cur.second;
            for (int i = 0; i < 4; i++) {
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if (nextx < 0 || nextx >= grid.size() || nexty < 0 ||
                    nexty >= grid[0].size()) {
                    continue;
                }
                if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
                    que.push({nextx, nexty});
                    visited[nextx][nexty] = true;
                    square++;
                }
            }
        }
        return square;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSquare = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    maxSquare = max(maxSquare, bfs(grid, visited, i, j));
                }
            }
        }
        return maxSquare;
    }
};
int main(){
  Solution s;
  vector<vector<int>>grid={{1,1,0,1,0,0,1,1},{0,1,0,1,1,1,1,0},{1,1,1,1,0,0,0,1}};
  cout<<"岛屿最大面积"<<s.maxAreaOfIsland(grid);
  system("pause");
  return 0;
}
