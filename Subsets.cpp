// https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>

using namespace std;

void backTracking(vector<int>& nums, int n, vector<vector<int>>& ans, vector<int> tmp, int k) {
    for(int i=k; i<n; ++i) {
        tmp.push_back(nums[i]);
        ans.push_back(tmp);
        backTracking(nums, n, ans, tmp, i+1);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> t = {};
    ans.push_back(t);
    int n = nums.size();
    vector<int> tmp;
    backTracking(nums, n, ans, tmp, 0);
    return ans;
}

int main()
{
    vector<int> t = {1,2,3};
    vector<vector<int>> m = subsets(t);
    for(int i=0; i<(int) m.size(); ++i) {
        for(int j=0; j<(int) m[i].size(); ++j) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
