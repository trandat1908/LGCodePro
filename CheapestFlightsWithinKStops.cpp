// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    struct Flight {
        int from;
        int to;
        int price;
        int countStop;
    };
    void dfs(const int& n, vector<Flight>& mvec, int src,const int& dst,const int& k) {
        for(int i=0; i<mvec[src].size(); ++i) {
            if(mvec[src][i].to==dst) {
                if(mvec[src][i].countStop + 1<=k && ) {
            }
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = filghts.size();
        vector<Flight> mvec(n);
        Flight f;
        for (int i = 0; i < m; ++i) {
            f.from = flights[i][0];
            f.to = flights[i][1];
            f.price = flights[i][2];
            f.countStop = 0;
            mvec[f.from].push_back(f);
        }



    }
};
int main()
{
    return 0;
}
