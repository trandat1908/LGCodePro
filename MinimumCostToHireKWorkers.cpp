https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double ans = 1e9;
        for(int captain = 0; captain < n; ++captain) {
            double factor = (double) wage[captain] / quality[captain];
            double prices[n];
            int c = 0;
            for(int worker = 0; worker < n; ++worker) {
                double price = factor * quality[worker];
                if(price < wage[worker]) continue;
                prices[c++] = price;
            }
            if(c < k) continue;
            sort(prices, prices + c);
            double cand = 0.00000;
            for(int i = 0; i < k; ++i) {
                cand += prices[i];
            }
            ans = min(ans, cand);
        }
        return ans;
    }
};
