https://leetcode.com/problems/couples-holding-hands/description/

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        for(int i=0; i<n; ++i) {
            row[i] = row[i]/2 + 1;
        }
        int cnt = 0;
        for(int i=0; i<n-1; i+=2) {
            //cout<<"i = "<<i<<endl;
            if(row[i] != row[i+1]) {
                cnt++;
                for(int j=i+2; j<n; ++j) {
                    if(row[j]==row[i]) {
                        int temp = row[j];
                        row[j] = row[i+1];
                        row[i+1] = temp;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};
