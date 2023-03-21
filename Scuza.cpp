// https://codeforces.com/problemset/problem/1742/E
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n, q;

bool sortInterval(vector<ll>& v1, vector<ll>& v2) {
    return v1[1]<v2[1];
}

int main()
{
    //freopen("D:/Code/Scuza/in.txt","r",stdin);
    cin>>t;
    while(t--) {
        cin>>n>>q;
        ll a[200005];
        vector<vector<ll>> k(q);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        a[n]= LONG_LONG_MAX;
        ll u = 0;
        for(int i=0; i<q; i++) {
            cin>>u;
            k[i].push_back(u);
            k[i].push_back(i);
            k[i].push_back(0);
        }
        sort(k.begin(),k.end());
        int v = 0;
        for(int i=0; i<q; i++) {
            ll s = 0;
            for(int j=v; j<=n;j++) {
                if(a[j]<=k[i][0]) {
                    s += a[j];
                } else {
                    v = j;
                    break;
                }
            }
            if(i>0) s+=k[i-1][2];
            k[i][2] = s;
        }
        sort(k.begin(), k.end(), sortInterval);
        for(int i=0; i<q; i++) {
            cout<<k[i][2]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
