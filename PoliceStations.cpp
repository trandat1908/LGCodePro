https://codeforces.com/contest/796/problem/D

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("F:\\Code\\PoliceStations\\in.txt","r",stdin);
    int n, k, d;
    cin>>n>>k>>d;
    queue<pair<int,int>> Q;
    vector<bool> visited(n+1, false);
    vector<vector<pair<int,int>>> G(n+1);
    set<int> edges;
    int t;
    for(int i=0; i<k; ++i) {
        cin>>t;
        Q.push({t, 0});
    }

    int u, v;
    for(int i=1; i<=(n-1); ++i) {
        cin>>u>>v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    while(!Q.empty()) {
        int p = Q.front().first;
        int f = Q.front().second;
        Q.pop();
        if(visited[p]) continue;
        visited[p] = true;

        for(auto x : G[p]) {
            if(x.first != f) {
                if(visited[x.first]) {
                    edges.insert(x.second);
                } else {
                    Q.push({x.first, p});
                }
            }
        }
    }
    cout<<edges.size()<<endl;
    for(auto x : edges) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
