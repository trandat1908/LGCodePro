//https://www.spoj.com/problems/SPIKES/
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
char A[41][41];
int visited[41][41];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans = 1000;
int cnt = 0;
void solve(int x, int y) {
    for(int i=0; i<4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&A[tx][ty]!='#'&&A[tx][ty]!='@'&&visited[tx][ty]==0) {
            if(A[tx][ty]=='s') {
                cnt++;
                visited[tx][ty]=1;
                solve(tx,ty);
                cnt--;
                visited[tx][ty]=0;
            }
            else if(A[tx][ty]=='x') {
                if(cnt<ans) ans = cnt;
                return;
            } else {
                visited[tx][ty]=1;
                solve(tx,ty);
                visited[tx][ty]=0;
            }
        }
    }
}

int main()
{
    freopen("D:/Code/SPIKY_MAZES/in.txt","r",stdin);
    cin>>n>>m>>k;
    int x, y;
    vector<pair<int,int>> mV;
    for(int i=0; i<n; i++) {
        cin>>A[i];
        for(int j=0; j<m; j++) {
            if(A[i][j]=='@') {
                x = i;
                y = j;
                mV.push_back(make_pair(x,y));
            }
            visited[i][j] = 0;
        }
    }
    for(int i=0; i<mV.size(); i++) {
        x = mV[i].first;
        y = mV[i].second;
        visited[x][y] = 1;
        cnt = 0;
        solve(x, y);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                visited[i][j] = 0;
            }
        }
    }
    //cout<<"ans= "<<ans<<endl;
    if(2*ans<=k) {
        cout<<"SUCCESS"<<endl;
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
