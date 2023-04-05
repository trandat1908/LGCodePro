// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size() == 1)
        //     return true;
        // vector<int> vec;
        // for(int i=0;i<nums.size();i++) {
        //     if(nums[i] == 0) vec.push_back(i);
        // }
        // if(!vec.size())
        //     return true;
        // for(int i=0;i<vec.size();i++)
        // {
        //     int t = vec[i];
        //     t--;
        //     bool res = false;
        //     while(t>=0)
        //     {
        //         if(nums[t] > (vec[i] - t)) res = true;
        //         else if(vec[i] == nums.size() -1) res = true;
        //         t--;
        //     }
        //     if(!res)
        //         return false;
        // }
        // return true;

        int n = nums.size();
        vector<bool> check(n, false);
        check[0] = true;
        for(int i=0; i<n-1; ++i) {
            if(check[i]==false) return false;
            else {
                int l = nums[i];
                if(l>=n) return true;
                else {
                    for(int j=i+1; j<=i+l; ++j) {
                        check[j] = true;
                    }
                }
            }
        }
        return check[n-1];                     
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;

        for(int i=0;i<nums.size();i++){
            max_jump = max(max_jump, i+nums[i]);
            if(max_jump < i+1)
            {
                break;
            }

        }
        return max_jump >= nums.size()-1; 
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int close = nums.size()-1;
        for(int i=close;i>=0;i--){
            if(i+nums[i] >= close) close = i;
        }

        return close == 0;
    }     
};
