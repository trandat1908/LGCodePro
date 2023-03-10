//https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;

int n, k;
int X[100005];
int Y[100005];
int cnt = 0;

int main() {
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cin>>X[i];
        Y[X[i]] = 1;
    }
    sort(X, X+n);
    int cnt = 0;
    int p;
    int i=0;
    while(i<=X[n-1]) {
        if(Y[i]==1) { 
            p = i + k;
            for(int j=p; j>=i; j--) {
                if(Y[j]==1) {
                    cnt++;
                    i = j+k;
                    break;
                }
            }
        } 
        i++; 
    }
    cout<<cnt<<endl;
    
    return 0;
}
