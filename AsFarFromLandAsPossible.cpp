https://leetcode.com/problems/as-far-from-land-as-possible/description/

class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        int n = grid.size();
        queue<pair<int,int>> q;
        pair<int, int> p;
        q.push({x, y});
        while(!q.empty()) {
            p = q.front();
            q.pop();
            for(int i =0; i<4; ++i) {
                int tx = p.first + dx[i];
                int ty = p.second + dy[i];
                if(tx<0||tx>=n||ty<0||ty>=n) continue;
                if(grid[tx][ty]==0 && ((visited[p.first][p.second] + 1)< visited[tx][ty])) {
                    visited[tx][ty] = visited[p.first][p.second] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j]==1) {
                    visited[i][j] = 0;
                    bfs(grid, visited, i, j);
                }
            }
        }
        int ans = -1;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(visited[i][j] != INT_MAX && visited[i][j]>0) {
                    ans = max(ans, visited[i][j]);
                }
            }
        }
        return ans;
    }
};


//DP

int n = grid.size();
        const int MAX_DIST = 2*n + 1;
        vector<vector<int>> dist(n, vector<int>(n, MAX_DIST));

        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j]==1) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = min(dist[i][j], min((i>0?dist[i-1][j]+1:MAX_DIST), (j>0?dist[i][j-1]+1:MAX_DIST)));
                }
            }
        }
        for(int i=n-1; i>=0; --i) {
            for(int j=n-1; j>=0; --j) {
                if(grid[i][j]==1) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = min(dist[i][j], min((i<n-1?dist[i+1][j]+1:MAX_DIST), (j<n-1?dist[i][j+1]+1:MAX_DIST)));
                }
            }
        }
        int ans = -1;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(dist[i][j] != 0 && dist[i][j] != MAX_DIST) {
                    ans = max(ans, dist[i][j]);
                }
            }
        }
        return ans;
