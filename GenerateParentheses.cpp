// https://leetcode.com/problems/generate-parentheses/description/

// Solution 1
// class Solution {
// public:
//     bool checkForm(vector<char> arr) {
//         int n = arr.size();
//         int c = 0;
//         for(int i=0; i<n; i++) {
//             if(arr[i]=='(') {
//                 c++;
//             } else {
//                 c--;
//             }
//             if(c<0) return false;
//         }
//         if(c!=0) return false;
//         return true;
//     }
//     void backTracking(vector<char> a, int k, vector<string>& S) {
//         if(k==a.size()) {
//             if(checkForm(a)) {
//                 string s(a.begin(), a.end());
//                 S.push_back(s);
//             }
//         } else {
//             a[k] = '(';
//             backTracking(a, k+1, S);
//             a[k] = ')';
//             backTracking(a, k+1, S);
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> S;
//         vector<char> a(2*n);
//         backTracking(a, 0, S);
//         return S;
//     }
// };

// Solution 2
class Solution {
public:
    
    void backTracking(vector<char> a, int k, int open, int close, vector<string>& S) {
        if(k==a.size()) {
            string s(a.begin(), a.end());
            S.push_back(s);
        } else {
            if(open<(a.size()/2)) {
                a[k] = '(';
                backTracking(a, k+1, open+1, close, S);
            } 
            if((close<(a.size()/2)) && (close<open)) {
                a[k] = ')';
                backTracking(a, k+1, open, close + 1, S);
            } 
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> S;
        vector<char> a(2*n);
        backTracking(a, 0, 0, 0, S);
        return S;
    }
};
