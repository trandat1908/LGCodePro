//https://leetcode.com/problems/combinations/

class Solution {
public:
    vector<vector<int>> results;
    vector<int> tmp;
    int N, K;
    void backtrack(int p) {
        for(int i=p ; i<=(N+1); ++i) {
            if((int)tmp.size()==K) {
                results.push_back(tmp);
                return;
            } else {
                tmp.push_back(i);
                backtrack(i+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        N = n;
        K = k;
        backtrack(1);
        return results;
    }
};
