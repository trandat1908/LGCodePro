// https://leetcode.com/problems/trapping-rain-water-ii/

#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     int calculateVolume(vector<vector<int>>& heightMap, const int& x, const int& y, const int& m, const int& n) {
//         int a = 0, b = 0, c = 0, d = 0, ret = INT_MAX;
//         for(int i=1; i<=4; ++i) {
//             switch (i) {
//                 case 1:
//                 {
//                     int ty = y;
//                     do{
//                         ty = y + 1;
//                         a = max(a, heightMap[x][ty]);
//                     } while(ty<n-1);
//                     break;
//                 }
//                 case 2:
//                 {
//                     int ty = y;
//                     do{
//                         ty = y - 1;
//                         b = max(b, heightMap[x][ty]);
//                     } while(ty>0);
//                     break;
//                 }
//                 case 3:
//                 {
//                     int tx = x;
//                     do{
//                         tx = x + 1;
//                         c = max(c, heightMap[tx][y]);
//                     } while(tx<m-1);
//                     break;
//                 }
//                 case 4:
//                 {
//                     int tx = x;
//                     do{
//                         tx = x - 1;
//                         d = max(d, heightMap[tx][y]);
//                     } while(tx>0);
//                     break;
//                 }
//                 default:
//                     break;
//             }
//         }
//         a = min(a, b);
//         c = min(c, d);
//         ret = min(a, c);
//         return ret;
//     }
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int m = heightMap.size();
//         int n = heightMap[0].size();
//         int volume = 0;
//         for(int i=1; i<(m-1); ++i) {
//             for(int j=1; j<(n-1); ++j) {
//                 int h = calculateVolume(heightMap, i, j, m, n);
//                 if(h > heightMap[i][j]) {
//                     volume += h - heightMap[i][j];
//                 }
//             }
//         }
//         return volume;
//     }
// };

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) {
            return 0;
        }
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
        int volume_water = 0;
        for(int i=0; i<m; ++i) {
            heap.push({heightMap[i][0], i, 0});
            heap.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }

        for(int i=1; i<n-1; ++i) {
            heap.push({heightMap[0][i], 0, i});
            heap.push({heightMap[m-1][i], m-1, i});
            visited[0][i] = visited[m-1][i] = true;
        }

        while(!heap.empty()) {
            auto [height, x, y] = heap.top();
            heap.pop();

            for(auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int tx = x + dx;
                int ty = y + dy;
                if(tx>=0&&tx<m&&ty>=0&&ty<n&&visited[tx][ty]==false) {
                    visited[tx][ty] = true;
                    int water_trapped = max(0, height - heightMap[tx][ty]);
                    volume_water += water_trapped;
                    heap.push({max(height, heightMap[tx][ty]), tx, ty});
                }
            }
        }
        return volume_water;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<vector<int>> heightMap = {{12, 13, 1, 12},
                                     {13, 4, 13, 12},
                                     {13, 8, 10, 12},
                                     {12, 13, 13, 12},
                                     {13, 13, 13, 12}};
    cout << sol->trapRainWater(heightMap) << endl;
    return 0;
}
