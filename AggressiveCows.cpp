// https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAXX 10e9+1
int t, N, C;
bool checkValid(vector<ll> A, ll m) {
    ll k = m+A[0];
    vector<ll>::iterator it;
    for(int i=1; i<C; i++) {
        it = lower_bound(A.begin(), A.end(), k);
        if(it == A.end()) {
            return false;
        } else {
            k = *it + m;
        }
    }
    return true;
}
int main()
{
    //freopen("D:/Code/AggressiveCows/in.txt","r",stdin);
    cin>>t;
    while(t--) {
        cin>>N>>C;
        vector<ll> stalls(N);
        for(int i=0; i<N; i++) {
            cin>>stalls[i];
        }
        sort(stalls.begin(), stalls.end());
        int l = 0, r = MAXX;
        while(l<=r) {
            ll m = (r-l)/2 + l;
            if(checkValid(stalls, m)) {
                l=m+1;
            } else {
                r=m-1;
            }
        }
        cout<<l-1<<endl;
    }
    return 0;
}
