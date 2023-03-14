// https://www.hackerrank.com/challenges/count-luck/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;
int t, n, m, k;
char grid[102][102];
int visited[102][102];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int sum = 0;
bool check = false;
void countLuck(int x, int y, int c) {
    for(int i=0; i<4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&grid[tx][ty]!='X'&&visited[tx][ty]==0) {
            if(grid[tx][ty]=='*') {
                sum = c;
                check = true;
                return;
            }
            if(grid[tx][ty]=='1') {
                visited[tx][ty] = 1;
                countLuck(tx, ty, c + 1);
                if(check) return;
            } else {
                visited[tx][ty] = 1;
                countLuck(tx, ty, c);
                if(check) return;
            }
        }
    }
}

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;
        int x, y;
        for(int i=0; i<n; i++) {
            cin>>grid[i];
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='M') {
                    x = i;
                    y = j;
                }
                visited[i][j] = 0;
            }
        }
        cin>>k;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='.'||grid[i][j]=='M') {
                    int count = 0;
                    for(int l = 0; l<4; l++) {
                        int tx = i + dx[l];
                        int ty = j + dy[l];
                        if(tx>=0&&tx<n&&ty>=0&&ty<m&&(grid[tx][ty]=='.'||grid[tx][ty]=='1'||grid[tx][ty]=='M'||grid[tx][ty]=='*')) {
                            count++;
                        }
                    }
                    
                    if(grid[i][j]=='.' && count>=3) grid[i][j] = '1';
                    else if(count>=2 &&grid[i][j]=='M') grid[i][j] = '1';
                }
            }
        }
        int c = 0;
        if(grid[x][y]=='1') c = 1;
        sum = 0;
        check = false;
        visited[x][y] = 1;
        countLuck(x, y, c);
        if(sum == k) {
            cout<<"Impressed"<<endl;
        } else {
            cout<<"Oops!"<<endl;
        }
    }
    return 0;
}
