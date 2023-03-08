#include <bits/stdc++.h>

using namespace std;

int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};
int G[11][11];
int ret = INT_MAX;
void solve(int n, int m, int x, int y){
    for(int i=0; i<8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&G[tx][ty]==0) {
            G[tx][ty] = 1;
            solve(n, m, tx, ty);
            int ans = 0;
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(G[i][j]==0) {
                        ans++;
                    }
                }
            }
            if(ans < ret) ret = ans;
            G[tx][ty] = 0;
        }
    }

}

int main()
{
    //freopen("D:/Code/Making_Jumps/in.txt","r",stdin);
    int n, cnt = 1;
    while(1) {
        cin>>n;
        if(n==0) break;
        int r, c, m=0;
        int x,y;
        bool f = false;
        ret = INT_MAX;
        for(int i=0; i<n; i++) {
            cin>>r>>c;
            if(c>0 && f==false) {
                x = i;
                y = r;
                f = true;
            }
            if((r+c)>m) m = r+c;
            for(int j=0; j<11; j++) {
                if(j<r||j>=(r+c)) G[i][j] = 2;
                else G[i][j] = 0;
            }
        }
        G[x][y] = 1;
        solve(n, m, x, y);
        if(ret!=1) {
            cout<<"Case "<<cnt<<", "<<ret<<" squares can not be reached."<<endl;
        } else {
            cout<<"Case "<<cnt<<", "<<ret<<" square can not be reached."<<endl;
        }

        for(int i=0; i<11; i++) {
            for(int j=0; j<11; j++) {
                G[i][j] = 0;
            }
        }
        cnt++;
    }
    return 0;
}
