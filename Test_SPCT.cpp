https://www.hackerrank.com/swct-pre-test
https://codeforces.com/contest/1183/problem/C
https://codeforces.com/contest/902/problem/B
https://codeforces.com/contest/124/problem/B
https://www.codechef.com/problems/LARGESTY
https://codeforces.com/contest/796/problem/D
https://codeforces.com/contest/1195/problem/C
https://codeforces.com/contest/1176/problem/C

DP

https://leetcode.com/problems/partition-equal-subset-sum/description/
https://leetcode.com/problems/last-stone-weight-ii/description/
https://atcoder.jp/contests/abc291/tasks/abc291_c

Greedy

https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/
https://leetcode.com/problems/minimize-maximum-of-array/description/
https://leetcode.com/problems/sum-game/description/


https://leetcode.com/problems/rectangle-overlap/
https://leetcode.com/problems/repeated-dna-sequences/
https://leetcode.com/problems/binary-watch/
https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

https://www.hackerrank.com/swct-pretest-2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h>
int nKid;
int nBag;
vector<int> bag;
vector<int> cfg;
 
int ans = INT_MAX;
 
// 1. Try to fill configuration cfg at position index
// 2. Continue to do it with position index + 1 by recursive
void bt(int index) {
    if (index == nBag) {
        // Process cfg
        int maxCandy = 0;
        for (auto e : cfg) maxCandy = max(maxCandy, e); 
        ans = min(ans, maxCandy);
        return;
    }
     
    for (int i = 0; i < nKid; i++) {
        cfg[i] += bag[index];
        bt(index + 1);
        cfg[i] -= bag[index];
    }
     
}
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     
    // int nKids;
    // int nBag;
    // vector<int> bag;
     
    // 1. Input
    cin >> nKid >> nBag;
    bag.resize(nBag, 0);
    cfg.resize(nKid, 0);
    for (int i = 0; i < nBag; i++) {
        cin >> bag[i];
    }
     
    // 2. Process
    bt(0);
    cout << ans << endl;
     
    return 0;
}
----------------------------------------
  #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
 
int nPeople;
int nRow;
 
vector<int> p;
 
vector<vector<int>> adj;
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
     
    // 1. Input
    cin >> nPeople >> nRow;
    p.resize(nPeople + 1, 0);
    adj.resize(nPeople + 1, {});
     
    for (int i = 1; i <= nPeople; i++) cin >> p[i];
     
    for (int i = 0; i < nRow; i++) {
        int a, b;
        cin >> a >> b;
         
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
     
     
     
    // 2. Process ans
     
    int ans = 0;
     
    vector<bool> visit(nPeople + 1, false);
    for (int i = 1; i <= nPeople; i++) {
        if (visit[i]) continue;
         
        visit[i] = true;
        // bfs
        int minVal = INT_MAX;
        queue<int> q;
        q.push(i);
         
        while (!q.empty()) {
            int index = q.front();
            q.pop();
 
            minVal = min(minVal, p[index]);
             
            for (auto neighbor : adj[index]) {
                if (visit[neighbor]) continue;
                visit[neighbor] = true;
                q.push(neighbor);
            }
        }
         
        ans += minVal;
 
    }
     ---------------------------------------------
       #include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, D, F;
    cin >> n;
    vector<int> d(n), f(n);
    for(int i = 0; i < n; ++i)
        cin >> d[i] >> f[i];
    cin >> D >> F;
    for(int i = 0; i < n; ++i) {
        d[i] = D - d[i];
        assert(d[i] > 0);
    }
    reverse(d.begin(), d.end());
    reverse(f.begin(), f.end());
     
    // F >= D -
    int cur = -1;
    int ans = 0;
    priority_queue<int> pq;
    while(F < D) {
        while(F >= d[cur+1]) {
            cur++;
            pq.push(f[cur]);
        }
        if(pq.empty())
            break;
        F += pq.top();
        pq.pop();
        ans++;
    }
    if(F >= D)
        cout << ans;
    else
        cout << "-1";
     
    return 0;
