#include <bits/stdc++.h>

using namespace std;
int n;

int visited[26][26];

void solve(int a, int b) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = 100;
        }
    }
    visited[0][0] = 1;
    visited[n-1][n-1] = 1000;
    queue<pair<int,int>> mQ;
    mQ.push(make_pair(0, 0));
    pair<int,int> mP;
    
    while(mQ.size()) {
        mP = mQ.front();
        mQ.pop();
        for(int u=0; u<8; u++) {
            int tx, ty;
            switch (u) {
                case 0:
                {
                    tx = mP.first + a;
                    ty = mP.second + b;
                    break;
                }
                case 1:
                {
                    tx = mP.first + a;
                    ty = mP.second - b;
                    break;
                }
                case 2:
                {
                    tx = mP.first - a;
                    ty = mP.second + b;
                    break;
                }
                case 3:
                {
                    tx = mP.first - a;
                    ty = mP.second - b;
                    break;
                }
                case 4:
                {
                    tx = mP.first + b;
                    ty = mP.second + a;
                    break;
                }
                case 5:
                {
                    tx = mP.first - b;
                    ty = mP.second + a;
                    break;
                }
                case 6:
                {
                    tx = mP.first + b;
                    ty = mP.second - a;
                    break;
                }
                case 7:
                {
                    tx = mP.first - b;
                    ty = mP.second - a;
                    break;
                }
                default:
                    break;
            }
            
            if(tx<0||tx>=n||ty<0||ty>=n) continue;
            int count_ = visited[mP.first][mP.second] + 1;
            if(tx==(n-1) && ty==(n-1)) {
                if(count_<visited[tx][ty]) {
                    visited[tx][ty] = count_;
                }
            } else {
                if(count_<visited[tx][ty]) {
                    visited[tx][ty] = count_;
                    mQ.push(make_pair(tx, ty));
                }
            }
        }
    }
}
int main() {
    cin>>n;
    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            solve(i,j);
            if(visited[n-1][n-1] == 1000) {
                cout<<-1<<" ";
            } else {
                cout<<visited[n-1][n-1]-1<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
