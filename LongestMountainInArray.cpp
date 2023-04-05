// https://leetcode.com/problems/longest-mountain-in-array/description/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        //------------------------------------------------
        // int n = arr.size();
        // int ret = 0, start = 0, end = 0;
        // while(start < n) {
        //     end = start;
        //     if(end + 1 < n && arr[end] < arr[end + 1]) {
        //         while(end+1<n && arr[end] < arr[end + 1]) end++;
        //         if(end + 1 < n && arr[end] > arr[end+1]) {
        //             while(end+1 < n && arr[end] > arr[end + 1]) end++;

        //             ret = max(ret, end - start + 1);
        //         }
        //     }
        //     start = max(end, start + 1);
        // }
        // return ret;
        //-------------------------------------------------
        // int n = arr.size();
        // vector<int> pos(n, 0);
        // int ret = 0;
        // bool up = false, down = false;
        // for(int i=0; i<n; ++i) {
        //     if(i+1<n && arr[i]<arr[i+1]) {
        //         if(down==true) {
        //             ret = max(ret, pos[i]+1);
        //             pos[i]=0;
        //         } 
        //         pos[i+1] = pos[i] + 1;
        //         up = true;
        //         down = false;
        //     } else if(i+1<n && arr[i] > arr[i+1]) {
        //         if(up==true) {
        //             pos[i+1] = pos[i] + 1;
        //             ret = max(ret, pos[i+1]+1);
        //             down = true;
        //         }
        //     } else if(i+1<n && arr[i] == arr[i+1]) {
        //         pos[i]=0; 
        //         pos[i+1] = 0;
        //         up = false; 
        //         down = false;
        //     }
        // }
        // return ret;
        //-----------------------------------------------------
        int n = arr.size();
        int ret = 0;
        vector<int> up(n, 1);
        vector<int> down(n, 1);

        for(int i=1; i<n; i++) {
            if(arr[i]>arr[i-1]) {
                up[i] = up[i-1] + 1;
            }
        }
        for(int i=n-2; i>=0; i--) {
            if(arr[i]>arr[i+1]) {
                down[i] = down[i+1] + 1;
            }
        }
        for(int i=0; i<n; i++) {
            if(up[i]>1 && down[i]>1) {
                ret = max(ret, up[i] + down[i] - 1);
            }
        }
        return ret;
    }
};
