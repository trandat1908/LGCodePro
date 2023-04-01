

// https://leetcode.com/problems/combination-sum/description/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int n;
    vector<vector<int>> results;

    void backtrack(vector<int>& a, vector<int> tmp, const int& target, int s, int k) {
        for(int i=k; i<n; i++) {
            if(s<target) {
                tmp.push_back(a[i]);
                s += a[i];
                backtrack(a, tmp, target, s, i);
                s -= a[i];
                tmp.pop_back();
            } else if(s>target) {
                return;
            } else {
                results.push_back(tmp);
                return;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        backtrack(candidates, tmp, target, 0, 0);
        return results;
    }
};
int main()
{
    Solution *s = new Solution();
    vector<int> c = {7,3,2};
    int target = 18;
    vector<vector<int>> ans;
    ans = s->combinationSum(c, target);
    for(int i=0; i<(int) ans.size(); ++i) {
        for(int j=0; j<(int) ans[i].size(); ++j) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"OK"<<endl;
    return 0;
}
