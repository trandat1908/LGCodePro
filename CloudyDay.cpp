#include <bits/stdc++.h>

using namespace std;

bool compareInterval(vector<int>& v1, vector<int>& v2) {
    return v1[1] <= v2[1];
}
int main() {
    //freopen("F:/Code/CloudyDay/in.txt","r",stdin);
    int n, m, x, y, r, p;
    int posMax=0;
    cin>>n;
    vector<vector<int>> towns(n);
    for(int i=0; i<n; i++) {
        cin>>p;
        towns[i].push_back(p);
    }
    for(int i=0; i<n; i++) {
        cin>>x;
        if(x>posMax) posMax = x;
        towns[i].push_back(x);
        towns[i].push_back(0);
    }
    cin>>m;
    vector<int> cloud(m);
    for(int i=0; i<m; i++) {
        cin>>y;
        cloud[i]= y;
    }
    cin>>r;
    for(int i=0; i<m; i++) {
        long a = (long) cloud[i] + r;
        long b = (long) cloud[i] - r;
        if(a>(long)posMax) a=posMax;
        if(b<0) b = 0;
        for(int j=0; j<n; j++) {
            if(towns[j][1]>=b&& towns[j][1]<=a) {
                towns[j][2]++;
            }
        }
    }
    sort(towns.begin(), towns.end(), compareInterval);
    int ans = 0;
    bool c = false;
    for(int i=n-1; i>=0; i--) {
        if(towns[i][2]==0){
            ans +=towns[i][0];
        }else if(towns[i][2]==1 && c == false) {
            ans +=towns[i][0];
            c = true;
        }
    }
    cout<<ans<<endl;
    return 0;
}
