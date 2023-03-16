// https://www.hackerrank.com/challenges/cut-the-tree/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;

int n;
int data_[100005];
int visited[100005];
int value[100005];
vector<int> *adj;

int cutTheTree(int p) {
    int s = 0;
    visited[p] = 1;
    for(int i=0; i<adj[p].size(); i++) {
        if(visited[adj[p][i]]==0) {
            s += cutTheTree(adj[p][i]);
        }
    }
    return value[p] = data_[p] + s; 
}

int main() {
    cin>>n;
    adj = new vector<int>[n+1];
    int sum = 0;
    for(int i=1; i<=n; i++) {
        cin>>data_[i];
        visited[i] = 0;
        value[i] = 0;
        sum += data_[i];
    }
    int u, v;
    for(int i=0; i<n-1; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cutTheTree(1);
    int ans = INT_MAX;
    for(int i=1; i<=n; i++) {
        if(abs(sum - (value[i]*2))<ans)
            ans = abs(sum - (value[i]*2));
    }
    cout<<ans<<endl;
    return 0;
}
