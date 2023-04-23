https://leetcode.com/problems/combination-sum-iii/description/ 

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(const int& k, const int& n, vector<int>& temp, int c) {
        if(temp.size() == k) {
            int sum = 0;
            for(auto x : temp) sum += x;
            if(sum == n) ans.push_back(temp);
            return;
        }
        for(int i=c; i<=9; ++i) {
            temp.push_back(i);
            backtrack(k, n, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        backtrack(k, n, temp, 1);
        return ans;
    }
};
