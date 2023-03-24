// https://leetcode.com/problems/heaters/

class Solution {
public:
    bool search(vector<int>& heaters, int &l, int &r, int& x) {
        while(l<=r) {
            int m = (r-l)/2 + l;
            if(x == heaters[m]) {
                return true;
            }
            if(x < heaters[m]) {
                r= m-1;
            } else {
                l= m+1;
            }
        }
        return false;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = heaters.size();
        int m = houses.size();
        int ans = 0;
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        for(int i=0; i<m; i++) {
            int l = 0;
            int r = n-1;
            if(search(heaters, l, r, houses[i])==false) {
                if(r>=0&&l<n){
                    int k = min(abs(heaters[l]-houses[i]),abs(heaters[r]-houses[i]));
                    ans = max(k, ans);
                } else if(r<=0&&l<n) {
                    ans = max(ans, abs(heaters[l]-houses[i]));
                } else if(l>=n&&r>=0) {
                    ans = max(ans, abs(heaters[r]-houses[i]));
                }
            }
        }
        return ans;
    }
};
