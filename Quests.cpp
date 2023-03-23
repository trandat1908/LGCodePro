https://codeforces.com/problemset/problem/1760/F

https://leetcode.com/problems/heaters/ 

https://www.spoj.com/problems/SCALE/ 


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAXK 10e9
#define MAXT 10e8
int t, n, d;
ll c;
bool sovle(vector<ll>& Q, ll k) {
    ll s = 0;
    for(int i=0; i<d; i++) {
        int j = 0;
        if(k!=1){
            j = i%k;
        }
        if(j<n) {
            s += Q[j];
        }
        if(s>=c) return true;
    }
    return false;
}
int main()
{
    freopen("D:/Code/Quests/in.txt","r",stdin);
    cin>>t;
    while(t--) {
        ll e;
        cin>>n>>c>>d;
        vector<ll> Q(n);
        bool g = false;
        for(int i=0; i<n; i++) {
            cin>> e;
            Q[i] = e;
        }
        sort(Q.begin(), Q.end(), greater<ll>());
        ll l = 1, r = MAXK;
        while(l<r) {
            ll k = (r-l)/2 + l;
            if(sovle(Q, k)) {
                l = k+1;
                g = true;
            } else {
                r = k;
            }
        }
        if(g==false) {
            cout<<"Impossible"<<endl;
        } else {
            if((l-2)>MAXT) {
                cout<<"Infinity"<<endl;
            } else {
                cout<<l-2<<endl;
            }
        }
    }
    return 0;
}

