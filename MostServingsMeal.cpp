// https://www.spoj.com/problems/MKUHAR/en/

#include <bits/stdc++.h>

using namespace  std;
int main() {
    freopen("D:/Code/MostServingsMeal/in.txt","r",stdin);
    int N, M, X, Y, SM, PM, SV, PV;
    cin>>N>>M;
    vector<vector<int>> Lisa(N);
    for(int i=0; i<N; i++) {
        cin>>X>>Y>>SM>>PM>>SV>>PV;
        Lisa[i].push_back(X);
        Lisa[i].push_back(Y);
        Lisa[i].push_back(SM);
        Lisa[i].push_back(PM);
        Lisa[i].push_back(SV);
        Lisa[i].push_back(PV);
    }
    int l = 0, r = M;
    while(l<r) {
        int m = l + (r-l+1)/2;
        int total = 0;
        for(int i=0; i<N; ++i) {
            int best = 1000001;
            int G = Lisa[i][0]*m - Lisa[i][1];
            int t = int (ceil(G/(float)Lisa[i][2]));
            for(int j=0; j<=t; j++) {
                int mass = j*Lisa[i][2];

                int u = (G>=mass)? int(ceil((G-mass)/(float)Lisa[i][4])):0;
                best = min(best, j*Lisa[i][3] + u*Lisa[i][5]);
            }
            if(best>M||(total + best) >M) {
                total = M+1;
                break;
            } else {
                total +=best;
            }
        }
        if(total<=M) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout<<l<<endl;
    return 0;
}
