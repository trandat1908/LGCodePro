https://codeforces.com/problemset/problem/1760/F

https://leetcode.com/problems/heaters/ 

https://www.spoj.com/problems/SCALE/ 


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main()
{
    freopen("D:/Code/Quests/in.txt","r",stdin);
    int t, n, d;
    ll c;
    cin>>t;
    while(t--) {
        cin>>n>>c>>d;
        vector<ll> quest(n);
        vector<ll> count(n);
        int u, m=0;
        ll s = 0;
        bool f = false;
        for(int i=0; i<n; i++) {
            cin>>u;
            if(u>m) m = u;
            if(i<d) {
                s += u;
                if(s>=c) {
                    f = true;
                }
            }
            quest[i] = u;
        }
        if(f) {
            cout<<"Infinity"<<endl;
            continue;
        }
        float c1= (float) c;
        c1 = (float) c1/m;
        if(c1>(float)d) {
            cout<<"Impossible"<<endl;
            continue;
        }
        sort(quest.begin(),quest.end(), greater<ll>());
        for(int i=1; i<=d; i++) {
            for(int j=0; j<n; i++) {
                
            }
        }
    }
    return 0;
}
