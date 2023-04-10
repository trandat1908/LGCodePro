// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

class Solution {
public:
    int m, n;
    int ans = 1;
    int ret = 1;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> grid{vector<vector<int>>(200, vector<int>(200, 1))};
    vector<vector<bool>> checked{vector<vector<bool>>(200, vector<bool>(200, false))};
    static bool intervalCompare(pair<int,pair<int,int>> &p1, pair<int,pair<int,int>> &p2) {
        return p1.first > p2.first;
    }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int count, int x, int y) {
        //cout<<"count = "<<count<<endl;
        if(count>ans) ans = count;
        if(count>ret) ret = count;
        for(int i=0; i<4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx>=0&&tx<m&&ty>=0&&ty<n&&visited[tx][ty]==false&&(matrix[tx][ty]>matrix[x][y])) {
                if(checked[tx][ty]==true) {
                    count += grid[tx][ty];
                    if(count > ans) ans = count;
                    if(count>ret) ret = count;
                    count -= grid[tx][ty];
                    continue;
                } 
                visited[tx][ty] = true;
                dfs(matrix, visited, count + 1, tx, ty);
                visited[tx][ty] = false;    
            }
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, pair<int, int>>> value;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                value.push_back({matrix[i][j], {i, j}});
            }
        }
        sort(value.begin(), value.end(), intervalCompare);
        for(int i=0; i<value.size(); ++i) {
            int x = value[i].second.first;
            int y = value[i].second.second;
            ret = 1;
            visited[x][y] = true;
            dfs(matrix, visited, 1, x, y);
            visited[x][y] = false;
            checked[x][y] = true;
            grid[x][y] = ret;
            //cout<<"x = "<<x<<" y = "<<y<<" ret = "<<ret<<endl;
        }
        
        return ans;
    }
};
