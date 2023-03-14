// https://www.hackerrank.com/challenges/short-palindrome/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'shortPalindrome' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */



int shortPalindrome(string s) {
    unsigned long long int ceil = int(pow(10,9))+7;
    unsigned long long int result = 0;
    unsigned long long int c1[26];
    unsigned long long int c2[26][26];
    unsigned long long int c3[26][26][26];
    for(int i=0;i<26;i++){
        c1[i]=0;
        for(int j=0;j<26;j++){
            c2[i][j]=0;
            for(int k=0;k<26;k++){
                c3[i][j][k] = 0;
            }
        }
    }
    if(s.length()<4){
        return 0;
    }
    for(auto letter: s){
        int c = letter-'a';
        for(int i =0;i<26;i++){
            result += c3[c][i][i]; //# times c,i,i,c in any position
            result %= ceil;
            c3[i][c][c] += c2[i][c]; //# of times i has preceded 2c's incremented by # times i has preceded 1c (because now is c)
            c2[i][c] += c1[i]; //# of times i has preceded 1c incremented by # times it has existed (because now is c)
        }
        c1[c]+=1;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = shortPalindrome(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

// ------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'shortPalindrome' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
vector<vector<int>> mVec(26);
long combination(int a, int k) {
    if(k==0||k==a) {
        return 1;
    } 
    return combination(a-1, k-1) + combination(a-1, k);
}
long shortPalindrome(int i, int j) {
    long ret = 0;
    for(int u=0; u<mVec[i].size()-1; u++) {
        for(int v=u+1; v<mVec[i].size(); v++) {
            int count_ = 0;
            for(int z=0; z<mVec[j].size(); z++) {
                if(mVec[j][z]>mVec[i][u]&&mVec[j][z]<mVec[i][v]) {
                    count_++;
                }
            }
            if(count_>=2)
                ret += (long) combination(count_, 2);
        }  
    }
    return ret;
}
long shortPalindrome(string s) {
    int n = s.length();
    int k;
    for(int i=0; i<n; i++) {
        k = (int) s[i] - 'a';
        mVec[k].push_back(i);
    }
    long sum = 0;
    for(int i=0; i<26; i++) {
        if(mVec[i].size()<=1) continue;
        for(int j=0; j<26; j++) {
            if(mVec[j].size()<=1) continue;
            if(i==j) {
                if(mVec[i].size()>=4) {
                    sum += combination(mVec[i].size(), 4);
                } else {
                    continue;
                }
            } else {
                sum += shortPalindrome(i, j);
            }
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long result = shortPalindrome(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

