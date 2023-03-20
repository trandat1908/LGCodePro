// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    bool checkForm(vector<char> arr) {
        int n = arr.size();
        int c = 0;
        for(int i=0; i<n; i++) {
            if(arr[i]=='(') {
                c++;
            } else {
                c--;
            }
            if(c<0) return false;
        }
        if(c!=0) return false;
        return true;
    }
    void backTracking(vector<char> a, int k, vector<string>& S) {
        if(k==a.size()) {
            if(checkForm(a)) {
                string s(a.begin(), a.end());
                S.push_back(s);
            }
        } else {
            a[k] = '(';
            backTracking(a, k+1, S);
            a[k] = ')';
            backTracking(a, k+1, S);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> S;
        vector<char> a(2*n);
        backTracking(a, 0, S);
        return S;
    }
};
