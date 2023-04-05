// https://leetcode.com/problems/domino-and-tromino-tiling/description/

class Solution {
public:
    int numTilings(int N) {
        vector<long long> ways(N+1, 0);
        long long M = 1e9 + 7;
        if(N==1) {
            return 1;
        } else if(N==2) {
            return 2;
        } else if(N==3) {
            return 5;
        } else {            
            ways[1] = 1;
            ways[2] = 2;
            ways[3] = 5;
            for(int i=4; i<=N; ++i) {
                ways[i] = (2*ways[i-1]+ways[i-3])%M;
            }
        }
        return ways[N];
    }
};
