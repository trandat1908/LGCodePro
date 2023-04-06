// https://leetcode.com/problems/trapping-rain-water-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int calculateVolume(vector<vector<int>>& heightMap, const int& x, const int& y, const int& m, const int& n) {
        int a = 0, b = 0, c = 0, d = 0, ret = INT_MAX;
        for(int i=1; i<=4; ++i) {
            switch (i) {
                case 1:
                {
                    int ty = y;
                    do{
                        ty = y + 1;
                        a = max(a, heightMap[x][ty]);
                    } while(ty<n-1);
                    break;
                }
                case 2:
                {
                    int ty = y;
                    do{
                        ty = y - 1;
                        b = max(b, heightMap[x][ty]);
                    } while(ty>0);
                    break;
                }
                case 3:
                {
                    int tx = x;
                    do{
                        tx = x + 1;
                        c = max(c, heightMap[tx][y]);
                    } while(tx<m-1);
                    break;
                }
                case 4:
                {
                    int tx = x;
                    do{
                        tx = x - 1;
                        d = max(d, heightMap[tx][y]);
                    } while(tx>0);
                    break;
                }
                default:
                    break;
            }
        }
        a = min(a, b);
        c = min(c, d);
        ret = min(a, c);
        return ret;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int volume = 0;
        for(int i=1; i<(m-1); ++i) {
            for(int j=1; j<(n-1); ++j) {
                int h = calculateVolume(heightMap, i, j, m, n);
                if(h > heightMap[i][j]) {
                    volume += h - heightMap[i][j];
                }
            }
        }
        return volume;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout << sol->trapRainWater(heightMap) << endl;
    return 0;
}
