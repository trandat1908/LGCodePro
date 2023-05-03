https://codeforces.com/contest/1176/problem/C

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("F:\\Code\\LoseIt\\in.txt","r",stdin);
    int n;
    cin>>n;
    int ans = 0;
    vector<queue<int>> nums(6);
    int t;
    for(int i=0; i<n; ++i) {
        cin>>t;
        if(t==4) {
            nums[0].push(i);
        } else if(t==8) {
            nums[1].push(i);
        } else if(t==15) {
            nums[2].push(i);
        } else if(t==16) {
            nums[3].push(i);
        } else if(t ==23) {
            nums[4].push(i);
        } else {
            nums[5].push(i);
        }
    }
    while(!nums[0].empty()&&!nums[1].empty()&&!nums[2].empty()&&!nums[3].empty()&&!nums[4].empty()&&!nums[5].empty()) {
        int p1 = nums[0].front();
        int p2 = nums[1].front();
        int p3 = nums[2].front();
        int p4 = nums[3].front();
        int p5 = nums[4].front();
        int p6 = nums[5].front();
        if(p1>p2) {
            ans++;
            nums[1].pop();
            continue;
        } else if(p2>p3) {
            ans++;
            nums[2].pop();
            continue;
        } else if(p3>p4) {
            ans++;
            nums[3].pop();
            continue;
        } else if(p4>p5) {
            ans++;
            nums[4].pop();
            continue;
        } else if(p5>p6) {
            ans++;
            nums[5].pop();
            continue;
        } else {
            nums[0].pop();
            nums[1].pop();
            nums[2].pop();
            nums[3].pop();
            nums[4].pop();
            nums[5].pop();
        }
    }
    ans += nums[0].size() + nums[1].size() + nums[2].size() + nums[3].size() + nums[4].size() + nums[5].size();
    cout<<ans<<endl;
    return 0;
}
