https://www.spoj.com/problems/TTBRM/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    //freopen("F:\\Code\\ToTheBird-planet\\in.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        int N,C,D;
        cin >> N >> C >> D;
        vector<int> Prices(N+1);

        for(int i=0;i<N;i++) {
            cin >> Prices[i];
        }
        ll cost = 0;
        ll fuel = C;
        cost += fuel*Prices[0];
        for(int i=1; i<=N; ++i) {
            //cout<<"i = "<<i<<" cost = "<<cost<<" fuel = "<<fuel<<endl;
            if(i!=N) {
                if(Prices[i] > Prices[i-1]) {
                    fuel = C - D;
                    cost -= fuel*Prices[i-1];
                    fuel = C;
                    cost += fuel*Prices[i];
                } else {
                    fuel = C - D;
                    cost += (C-fuel)*Prices[i];
                    //cout<<"fuel = "<<fuel<<" Prices[i] = "<<Prices[i]<<endl;
                    fuel = C;
                }
            }
            else {
                cost -= (C-D)*Prices[i-1];
            }
        }

        cout << cost << endl;
    }
    return 0;
}
