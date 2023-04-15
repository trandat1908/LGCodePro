https://www.spoj.com/problems/ELEVTRBL/

#include <bits/stdc++.h>

using namespace std;
int f, s, g, u, d;

int main()
{
    freopen("F:\\Code\\ElevatorTrouble\\in.txt","r",stdin);
    cin>>f>>s>>g>>u>>d;
    queue<pair<int, int>> floor;
    vector<int> visited(f+1, 2000005);
    floor.push({s, 0});
    visited[s] = 0;
    pair<int, int> p;
    while(!floor.empty()) {
        p = floor.front();
        floor.pop();
        int a = p.first + u;
        int b = p.first - d;
        int c = p.second + 1;
        if(a<=f && c < visited[a]){
            visited[a] = c;
            floor.push({a, c});
        }

        if(b>=1 && c < visited[b]) {
            visited[b] = c;
            floor.push({b, c});
        }
    }
    if(visited[g]==2000005) {
        cout<<"use the stairs"<<endl;
    } else {
        cout<<visited[g]<<endl;
    }

    return 0;
}
