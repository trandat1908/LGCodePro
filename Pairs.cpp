//https://www.hackerrank.com/challenges/pairs/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    long u;
    unordered_map<long, int> uMap;
    long arr[100005];
    for(int i=0; i<n; i++) {
        cin>>u;
        uMap[u] = 1;
        arr[i] = u;
    }
    int ans = 0;
    long s = 0;
    for(int i=0; i<n; i++) {
        s = arr[i] + k;
        if(uMap.find(s)!= uMap.end()) {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
