// https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:

    void backtrack(vector<int>& candidates, vector<vector<int>>& nums, vector<int> tmp, int& target, int& n, int k, int s) {
    for(int i=k; i<n; ++i) {
        int t = s + candidates[i];
        if(t>target) {
            return;
        } else if(t==target) {
            tmp.push_back(candidates[i]);
            nums.push_back(tmp);
            tmp.pop_back();
            return;
        } else {
            tmp.push_back(candidates[i]);
            backtrack(candidates, nums, tmp, target, n, i+1, t);
            tmp.pop_back();
            while((i+1)<n&&candidates[i+1]==candidates[i]) i++;
        }
    }

}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> nums;
    vector<int> tmp;
    int n = (int)candidates.size();
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, nums, tmp, target, n, 0, 0);
    return nums;
}

};



---------------------------------------------------------------------
    
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> comb;
        map<int,int> counter;
        for(int candidate : candidates) {
            if(counter.find(candidate) == counter.end()) {
                counter[candidate] = 1;
            } else {
                counter[candidate]++;
            }
        }
        vector<pair<int,int>> counterList;
        map<int,int>::iterator it;
        for(it = counter.begin(); it != counter.end(); ++it) {
            counterList.push_back({it->first, it->second});
        }
        backtrack(comb, target, 0, counterList, results);
        return results;
    }


    void backtrack(vector<int> comb, int remain, int curr, vector<pair<int,int>> counter, vector<vector<int>>& results) {
        if(remain <= 0) {
            if(remain==0) {
                results.push_back(comb);
            }
            return;
        }
        for(int nextCurr = curr; nextCurr < counter.size(); ++nextCurr) {
            pair<int,int> entry = counter[nextCurr];
            int candidate = entry.first; 
            int freq = entry.second;
            if(freq<=0) continue;

            comb.push_back(candidate);
            counter[nextCurr].second = freq - 1;
            backtrack(comb, remain - candidate, nextCurr, counter, results);

            comb.pop_back();
            counter[nextCurr].second = freq;

        }
    }
};

int main() {
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;
    Solution *so = new Solution();
    vector<vector<int>> results = so->combinationSum2(candidates, target);
    for(vector<int> comb : results) {
        for(int i : comb) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}


