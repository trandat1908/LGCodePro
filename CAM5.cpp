https://www.spoj.com/problems/CAM5/
https://www.spoj.com/problems/PT07Y/
https://www.codechef.com/problems/FIRESC


https://www.spoj.com/status/PT07Y,dattran1908/
https://www.codechef.com/viewsolution/94322881

#include <bits/stdc++.h>
 
using namespace std;
 
int _count = 0;
void dfs(vector<vector<int>>& edges, vector<bool>& visited, int node) {
    for(int i=0; i<edges[node].size(); ++i) {
        if(visited[edges[node][i]]==false) {
            visited[edges[node][i]] = true;
            _count++;
            dfs(edges, visited, edges[node][i]);
        }
    }
}
 
int main()
{
    //freopen("F:\\Code\\IsATree\\in.txt", "r", stdin);
    int N, M, u, v;
    cin>>N>>M;
    if(M>=N) {
        cout<<"NO"<<endl;
    } else {
        vector<vector<int>> edges(N+1);
        vector<bool> visited(N+1, false);
        for(int i=0; i<M; ++i){
            cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        visited[1] = true;
        dfs(edges, visited, 1);
        if(_count == N-1) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
 
    return 0;
}
 
