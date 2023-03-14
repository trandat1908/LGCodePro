// https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;

int n, m;
int matrix[11][11];
int visited[11][11];

int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};

int connectedCell(int x, int y) {
    int cells = 1;
    queue<pair<int,int>> mQ;
    pair<int,int> mP;
    mQ.push(make_pair(x, y));
    visited[x][y] = 1;
    while(mQ.size()) {
        mP = mQ.front();
        mQ.pop();
        for(int i=0; i<8; i++) {
            int tx = mP.first + dx[i];
            int ty = mP.second + dy[i];
            
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&visited[tx][ty]==0&&matrix[tx][ty]==1) {
                cells +=1;
                visited[tx][ty] = 1;
                mQ.push(make_pair(tx, ty));
            }
        }
    }
    return cells;
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>matrix[i][j];
            visited[i][j] = 0;
        }
    }
    int ans = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j]==1&&visited[i][j]==0) {
                //cout<<"i= "<<i<<" j= "<<j<<endl;
                int ret = connectedCell(i, j);
                //cout<<ret<<endl;
                if(ret>ans) ans = ret;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

