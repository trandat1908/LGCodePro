// https://www.hackerrank.com/challenges/beautiful-pairs/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;
int n;
int A[1005];
int B[1005];
int main() {
    cin>>n;
    int u, v;
    for(int i=0; i<n; i++) {
        cin>>u;
        A[u]++;
    }
    for(int i=0; i<n; i++) {
        cin>>v;
        B[v]++;
    }
    int count = 0;
    bool flag = false;
    for(int i=0; i<1005; i++) {
        if(A[i]==B[i]) {
            count += A[i];
        } else {
            if(A[i]>B[i]) {
                count += B[i];
            } else if(A[i]<B[i]) {
                count += A[i];
                if(flag==false) {
                    count++;
                    flag=true;
                }
            }
            
        }
    }
    if(flag==false) {
        count -= 1;
    }
    cout<<count<<endl;
    
    return 0;
}
