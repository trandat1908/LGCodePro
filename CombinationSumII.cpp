// https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:

    bool isRepeat(vector<vector<int>>&nums, vector<int> mV) {
        for(int i=0; i< (int)nums.size(); ++i) {
            if(mV[0]==nums[i][0]) {
                bool c = true;
                int n1 = nums[i].size();
                int n2 = mV.size();
                int a = 0, b = 0;
                while(a<n1&&b<n2) {
                    if(mV[b]!=nums[i][a]) {
                        c = false;
                    }
                    a++;
                    b++;
                } 
                if(c) return true;
            }
        }
        return false;
    }
    void backtrack(vector<int>& candidates, vector<vector<int>>& nums, vector<int> tmp, int& target, int& n, int k, int s, bool& c, int& cnt) {
    for(int i=k; i<n; ++i) {
        int t = s + candidates[i];
        if(i==n-1) cnt++;
        if(t>target) {
            return;
        } else if(t==target) {
            tmp.push_back(candidates[i]);
            if(isRepeat(nums, tmp)==false){
                nums.push_back(tmp);
            }
            tmp.pop_back();
            return;
        } else {
            if(i==n-1) {
                if(cnt==1)
                    c = true;
            }
            tmp.push_back(candidates[i]);
            backtrack(candidates, nums, tmp, target, n, i+1, t, c, cnt);
            if(c) return;
            tmp.pop_back();
        }
    }

}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> nums;
    vector<int> tmp;
    int n = (int)candidates.size();
    vector<int> mV(51, 0);
    for(int i=0; i<n; ++i) {
        if(mV[candidates[i]]<(target/candidates[i] + 1))
            mV[candidates[i]]++;
    }
    candidates.clear();
    for(int i=0; i<51; i++) {
        for(int j=0; j<mV[i]; ++j) {
            candidates.push_back(i);
        }
    }
    n = (int)candidates.size();
    for(int i=0; i<n; ++i) {
        cout<<candidates[i]<<" ";
    } 
    sort(candidates.begin(), candidates.end());
    bool c = false;
    int cnt = 0;
    backtrack(candidates, nums, tmp, target, n, 0, 0, c, cnt);
    return nums;
}

};
