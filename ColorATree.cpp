https://codeforces.com/contest/902/problem/B

#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
    freopen("F:\\Code\\ColoringATree\\in.txt","r",stdin);
    cin>>n;
    vector<vector<int>> P(n+1);

    vector<int> C(n+1);
    vector<int> A(n+1);
    int t;
    for(int i=2; i<=n; i++) {
        cin>>t;
        P[t].push_back(i);
    }
    for(int i=1; i<=n; ++i) {
        cin>>C[i];
        A[i] = 0;
    }
    int steps = 0;
    for(int i=1; i<=n; ++i) {
        if(A[i]!=C[i]){
            steps ++;
            stack<int> S;
            S.push(i);
            A[i] = C[i];
            int s;
            while(!S.empty()) {
                s = S.top();
                S.pop();
                for(auto x : P[s]) {
                    if(A[x] != C[i]) {
                        A[x] = C[i];
                        S.push(x);
                    }
                }
            }
        }
    }
    cout<<steps<<endl;
    return 0;
}
