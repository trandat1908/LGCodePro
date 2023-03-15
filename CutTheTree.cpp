// https://www.hackerrank.com/challenges/cut-the-tree/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;
int n;
int data_[100005];
int visited[100005];
long sum1 = 0;
void findSum(int p, vector<vector<int>>& adj, int v) {
    sum1 += data_[p];
    for(int i=0; i<adj[p].size(); i++) {
        if(adj[p][i] != v && visited[adj[p][i]]==0) {
            visited[adj[p][i]]= 1;
            findSum(adj[p][i], adj, v);
            visited[adj[p][i]]= 0;
        }
    }
}

int main() {
    //freopen("D:/Code/CutTheTree/in.txt","r",stdin);
    cin>>n;
    vector<vector<int>> adj(n+1);
    vector<pair<int,int>> edges(n);
    long sum = 0;
    for(int i=1; i<=n; i++) {
        cin>>data_[i];
        visited[i] = 0;
        sum += (long) data_[i];
    }
    int u, v;
    for(int i=0; i<n-1; i++) {
        cin>>u>>v;
        edges[i].first = u;
        edges[i].second = v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long ans = LONG_MAX;
    for(int i=0; i<n-1; i++) {
        u = edges[i].first;
        v = edges[i].second;
        sum1 = 0;
        visited[u] = 1;
        findSum(u, adj, v);
        visited[u] = 0;
        long sum2 = sum - sum1;
        
        if(abs(sum1-sum2)<ans) ans = abs(sum1-sum2);
    }
    cout<<ans<<endl;
    return 0;
}
