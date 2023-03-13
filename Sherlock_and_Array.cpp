//https://www.hackerrank.com/challenges/sherlock-and-array/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;
int T, n;
int arr[100005];
int A[100005];
int B[100005];
int main() {
    cin>>T;
    while(T--) {
        cin>>n;
        long s = 0;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            s += arr[i];
            A[i] = s;
        }
        s = 0;
        for(int i=n-1; i>=0; i--) {
            s += arr[i];
            B[i] = s;
        }
        bool ret = false;
        for(int i=0; i<n; i++) {
            if(A[i]==B[i]) {
                ret = true;
                break;
            }
        }
        if(ret)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    
    return 0;
}
