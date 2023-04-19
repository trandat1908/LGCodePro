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


bool internalCompare(pair<int, int>& p1, pair<int,int>& p2) {
    return (double) p1.second/p1.first < (double) p2.second/p2.first;
}

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int N = quality.size();
        vector<pair<int,int>> workers(N);
        for (int i = 0; i < N; ++i) {
            workers[i].first = quality[i];
            workers[i].second = wage[i];
        }
        
        sort(workers.begin(), workers.end(), internalCompare);

        double ans = 1e9;
        int sumq = 0;
        priority_queue<int> pool;
        for (auto worker : workers) {
            pool.push(worker.first);
            sumq += worker.first;
            if (pool.size() > K) {
                sumq -= pool.top(); pool.pop();
            }
                
            if (pool.size() == K) {
                ans = min(ans, sumq * ((double)worker.second/worker.first));
            }
        }
        return ans;
    }
};
