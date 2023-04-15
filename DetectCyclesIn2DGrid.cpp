https://leetcode.com/problems/detect-cycles-in-2d-grid/

class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m, n;
    bool isCycle = false;
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, const char& c, pair<int,int> curP, pair<int,int> preP) {
        for(int i=0; i<4; ++i) {
            int tx = dx[i] + curP.first;
            int ty = dy[i] + curP.second;
            if(tx<0||tx>=m||ty<0||ty>=n||grid[tx][ty] != c) continue;
            if(visited[tx][ty]!=0) {
                if(tx!=preP.first && ty!= preP.second) {
                    isCycle = true;
                    return;
                } else {
                    continue;
                }
            } else {
                visited[tx][ty] = 1;
                pair<int,int> temp{tx, ty};
                dfs(grid, visited, c, temp, curP);
                if(isCycle) return;
            }
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(visited[i][j] == 0) {
                    visited[i][j] = 1;
                    pair<int, int> p1{i, j};
                    pair<int,int> p2{-1, -1};
                    dfs(grid, visited, grid[i][j], p1, p2);
                    if(isCycle) return true;
                }
            } 
        }
        return false;
    }
};
