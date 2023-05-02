https://codeforces.com/contest/124/problem/B

#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<vector<string>> perm;
void permute(string& a, int l, int r, int &p)
{
    // Base case
    if (l == r)
        perm[p].push_back(a);
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l + 1, r, p);

            // backtrack
            swap(a[l], a[i]);
        }
    }
}
int main()
{
    freopen("F:\\Code\\Permutations\\in.txt","r",stdin);
    cin>>n>>k;
    perm.resize(n);
    string s = "";
    for(int i=0; i<n; ++i) {
        cin>>s;
        permute(s, 0, k-1, i);
    }
    int ans = INT_MAX;
    for(int i=0; i<(int)perm[0].size(); ++i) {
        int ma = 0;
        int mi = INT_MAX;
        for(int j=0; j<(int)perm.size(); ++j) {
            //cout<<perm[j][i]<<endl;
            int a = stoi(perm[j][i]);
            ma = max(a, ma);
            mi = min(a, mi);
        }
        ans = min(ans, abs(ma - mi));
    }
    cout<<ans<<endl;
    return 0;
}
