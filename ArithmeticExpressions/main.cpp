#include <bits/stdc++.h>

using namespace std;
int n;
int A[10005];
int hash_[10005][102];
char operators[10005];
bool c = false;
void recursion(int p, int s) {
    cout<<"p= "<<p<<" s= "<<s<<" A[p]= "<<A[p]<<endl;

    if(s==0){
        c = true;
        return;
    }
    if(p==n-1) {
        return;
    }
    if(s<0) {
        if(hash_[p][s*(-1)]==1) {
            return;
        } else {

            hash_[p][s*(-1)] = 1;
            cout<<"*"<<endl;
            recursion(p+1, (s*A[p+1])%101);
            if(c) {
                operators[p] = '*';
            }
            cout<<"+"<<endl;
            recursion(p+1, (s+A[p+1])%101);

            if(c) {
                operators[p] = '+';
            }
            cout<<"-"<<endl;
            recursion(p+1, (s-A[p+1])%101);
            if(c) {
                operators[p] = '-';
            }
        }
    } else {
        if(hash_[p][s]==1) {
            return;
        } else {

            hash_[p][s] = 1;
            cout<<"*"<<endl;
            recursion(p+1, (s*A[p+1])%101);
            if(c) {
                operators[p] = '*';
            }
            cout<<"+"<<endl;
            recursion(p+1, (s+A[p+1])%101);
            if(c) {
                operators[p] = '+';
            }
            cout<<"-"<<endl;
            recursion(p+1, (s-A[p+1])%101);
            if(c) {
                operators[p] = '-';
            }
        }
    }
}



int main() {
    freopen("C:/Users/Dat Tran/OneDrive/Desktop/LGCodePro/ArithmeticExpressions/in.txt","r",stdin);
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>A[i];
    }

    recursion(0, A[0]);
    cout<<A[0];
    for(int i=0;i<n-1;i++) {
        cout<<operators[i]<<A[i+1];
    }
    cout<<endl;
    return 0;
}
