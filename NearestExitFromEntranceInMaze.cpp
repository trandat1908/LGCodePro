https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

class Solution {
public:
    int m, n;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    // int ans = INT_MAX;
    // void dfs(vector<vector<char>>& maze, vector<vector<bool>>& visited, int x, int y, int step) {
    //     for(int i=0; i<4; ++i) {
    //         int tx = x + dx[i];
    //         int ty = y + dy[i];
    //         if(tx>=0 && tx<m && ty>=0 && ty<n && maze[tx][ty]=='.' &&visited[tx][ty]==false) {
    //             //cout<<"tx = "<<tx<<" ty = "<<ty<<endl;

    //             visited[tx][ty] = true;
    //             //cout<<"step = "<<step<<endl;
    //             if(tx==0||tx==m-1||ty==0||ty==n-1) {
    //                 ans = min(ans, step+1);
    //                 visited[tx][ty] = false;
    //                 return;
    //             }
    //             dfs(maze, visited, tx, ty, step+1);
    //             //visited[tx][ty] = false;
    //         }
    //     }
    // }
    int bfs(vector<vector<char>>& maze, vector<vector<bool>>& visited, vector<vector<int>>& steps, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        pair<int,int> p;
        while(!q.empty()) {
            p = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                int tx = p.first + dx[i];
                int ty = p.second + dy[i];
                if(tx>=0 && tx<m && ty>=0 && ty<n && maze[tx][ty]=='.' && visited[tx][ty]==false) {
                    //cout<<"tx = "<<tx<<" ty = "<<ty<<endl;
                    visited[tx][ty] = true;
                    //cout<<"step = "<<step<<endl;
                    steps[tx][ty] = steps[p.first][p.second] + 1;
                    if(tx==0||tx==m-1||ty==0||ty==n-1) {
                        return steps[tx][ty];
                    }
                    q.push({tx, ty});
                }
            }
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> steps(m, vector<int>(n, 0));
        int x = entrance[0];
        int y = entrance[1];
        visited[x][y] = true;
        //dfs(maze, visited, x, y, 0);

        int ans = bfs(maze, visited, steps, x, y);
        return ans;
    }
};
