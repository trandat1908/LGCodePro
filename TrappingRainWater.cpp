// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> mid(n, 0);

        left[0] = height[0];
        right[n-1] = height[n-1];
        int maxl = left[0];
        int maxr = right[n-1];
        for(int i=0; i<n; ++i) {
            maxl = max(maxl, height[i]);
            left[i] = maxl;
        }
        for(int i=n-1; i>=0; --i) {
            maxr = max(maxr, height[i]);
            right[i] = maxr;
        }
        for(int i=0; i<n; ++i) {
            mid[i] = min(left[i], right[i]);
        }
        int s = 0;
        for(int i=0; i<n; ++i) {
            s += abs(height[i]- mid[i]);
        } 
        return s;
    }
};


class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};
