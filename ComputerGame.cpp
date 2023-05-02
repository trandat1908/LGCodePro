// https://codeforces.com/contest/1183/problem/C

#include <bits/stdc++.h>

using namespace std;
int q, k, n, a, b;
int main()
{
    freopen("F:\\Code\\ComputerGame\\in.txt","r",stdin);
    cin>>q;
    while(q--) {
        cin>>k>>n>>a>>b;
        float t1 = (float) k/b;
        float t2 = (float) k/a;
        if(t1 <= (float) n) {
            cout<<-1<<endl;
        } else if(t2>(float)n) {
            cout<<n<<endl;
        } else {
            int l = 0;
            int r = k/a;
            while(l<=r) {
                int m = (r-l)/2 + l;
                int s = m*a;
                int u = (n - m) * b;
                if((s+u) < k) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
            if(l==0) {
                cout<<l<<endl;
            } else {
                cout<<l-1<<endl;
            }
        }
    }

    return 0;
}
