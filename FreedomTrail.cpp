// https://leetcode.com/problems/freedom-trail/description/

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length();
        vector<vector<pair<int, int>>> mv(26);
        int c, d;
        for(int i=0; i<n; ++i) {
            c = ring[i] - 'a';
            mv[c].push_back({i, 0});
        }
        int preP, curP;
        for(int i=0; i<m; ++i) {
            c = key[i] - 'a';
            //cout<<"i = "<<i<<" key[i] = "<<key[i]<<endl;
            for(int j=0; j<(int)mv[c].size(); ++j) {
                //cout<<"mv[c][j] = "<<mv[c][j].second<<endl;
                if(i==0) {
                    int x = INT_MAX;
                    preP = 0;
                    curP = mv[c][j].first;
                    x = min(x, min(abs(curP - preP), abs(n -  abs(curP - preP))));
                    mv[c][j].second += x;
                } else {
                    d = key[i-1] - 'a';
                    int h = INT_MAX;
                    for(int k=0; k<(int)mv[d].size(); ++k) {
                        int x = INT_MAX;
                        preP = mv[d][k].first;
                        curP = mv[c][j].first;
                        x = min(abs(curP - preP), abs(n -  abs(curP - preP)));
                        h = min(h,x + mv[d][k].second);
                        //cout<<"h = "<<h<<endl;
                    }
                    mv[c][j].second = h;
                }
            }
        }
        int ans = INT_MAX;
        c = key[m-1] - 'a';
        for(int i=0; i<(int) mv[c].size(); ++i) {
            ans = min(ans, mv[c][i].second);
        }
        ans += m;
        return ans;
    }
};
