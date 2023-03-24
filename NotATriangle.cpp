// https://www.spoj.com/problems/NOTATRI/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("D:/Code/NotATriangle/in.txt","r",stdin);
    int N;
    while(true) {
        cin>>N;
        if(N==0) break;
        vector<int> S(N);
        for(int i=0; i<N; i++) {
            cin>>S[i];
        }
        sort(S.begin(), S.end());
        int ans = 0;
        for(int i=0; i<N-2; ++i) {
            for(int j=i+1; j<N-1; ++j) {
                int k = S[i] + S[j];
                int l = j + 1;
                vector<int>::iterator it;
                it = upper_bound(S.begin() + l, S.end(), k);
                if(it != S.end()) {
                    int u = it - S.begin();
                    int v = N - u;
                    ans +=v;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
