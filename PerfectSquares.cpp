// https://leetcode.com/problems/perfect-squares/description/

class Solution {
public:
    int ans = INT_MAX, m;
    void backtrack(vector<int>& square,const int& n, int k, int count_, int sum) {
        for(int i=k; i<m; ++i) {
            if(sum>n) {
            return;
            } else if(sum==n) {
                if(count_<ans) ans = count_;
                return;
            } else {
                int u = (n-sum)/square[i];
                u = (u==0) ? 1 : u;
                sum += square[i]*u;
                count_ += u;
                backtrack(square, n, i, count_, sum);
                sum -= square[i]*u;
                count_ -= u;
            }
        } 
    }
    int numSquares(int n) {
        vector<int> square;
        int a = 1, b = 1;
        while(a<=n) {
            square.push_back(a);
            b++;
            a = b*b;
        }
        sort(square.begin(), square.end(), greater<int>());
        m = square.size();
        backtrack(square, n, 0, 0 , 0);
        return ans;
    }
};

//-----------------------------------------------------------------
vector<int> dp(n+1, 0);
for(int i=1; i<=n; ++i) {
    int count = INT_MAX;
    for(int j=1; j*j<=i; ++j) {
        count = min(count, dp[i-j*j] + 1);
    }
    dp[i] = count;
}
return dp[n];
