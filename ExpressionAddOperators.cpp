https://leetcode.com/problems/expression-add-operators/
//Wrong answer
class Solution {
public:
    int n;
    vector<string> ans;
    long long findSum(const string& num, vector<char>& temp) {
        stack<int> mS;
        mS.push(num[0]-48);
        for(int i=0; i<(int)temp.size(); ++i) {
            if(temp[i]=='+'||temp[i]=='-') {
                mS.push(num[i+1]-48);
            } else {
                int a = mS.top();
                mS.pop();
                int b = num[i+1] - 48;
                mS.push(a*b);
                temp[i] = '@';
            }
        }
        vector<int> A;
        vector<int> B;
        int c;
        while(!mS.empty()) {
            c = mS.top();
            mS.pop();
            A.push_back(c);
        }
        for(int i=0; i<(int) temp.size(); i++) {
            if(temp[i]=='+'||temp[i]=='-') {
                B.push_back(temp[i]);
            }
        }
        reverse(A.begin(), A.end());
        long long sum = A[0];
        for(int i=0; i<(int) B.size(); ++i) {
            if(B[i]=='+') {
                sum += A[i+1];
            } else {
                sum -= A[i+1];
            }
        }
        return sum;
    }
    void backtrack(string& num,const int& target, vector<char>& temp) {
        //cout<<temp.size()<<endl;
        if(temp.size() == (n-1)) {
            long long sum = findSum(num, temp); 
            if(sum == target) {
                string s = "";
                s += num[0];
                for(int i=0; i<(int) temp.size(); ++i) {
                    if(temp[i]=='@') temp[i] = '*';
                    s += temp[i];
                    s += num[i+1];
                }
                ans.push_back(s);
            }
            return;
        }
        temp.push_back('+');
        backtrack(num, target, temp);
        temp.pop_back();
        temp.push_back('-');
        backtrack(num, target, temp);
        temp.pop_back();
        temp.push_back('*');
        backtrack(num, target, temp);
        temp.pop_back();
    }
    vector<string> addOperators(string num, int target) {
        n = num.length();
        vector<char> temp;
        backtrack(num, target, temp);
        return ans;
    }
};
