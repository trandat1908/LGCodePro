#include <bits/stdc++.h>

using namespace std;
int n;
int hash_[10005][102];
int hashminus[10005][102];
int arr[10005];
char operators[10005];
bool c = false;

void perform(int p, int s) {
    cout<<"p= "<<p<<" s= "<<s<<" arr[p]= "<<arr[p]<<endl;
    if(p>n) {
        if(s==0) {
            c = true;
        }
        return;
    }

    if(s<0) {
        if(hashminus[p][s*(-1)]==1) {
            return;
        } else {
            hashminus[p][s*(-1)] = 1;
            cout<<"*"<<endl;
            perform(p+1, (s*arr[p])%101);
            if(c) {
                operators[p-2] = '*';
                return;
            }
            cout<<"+"<<endl;
            perform(p+1, (s+arr[p])%101);
            if(c) {
                operators[p-2] = '+';
                return;
            }
            cout<<"-"<<endl;
            perform(p+1, (s-arr[p])%101);
            if(c) {
                operators[p-2] = '-';
                return;
            }
        }
    } else {
        if(hash_[p][s]==1) {
            return;
        } else {
            hash_[p][s] = 1;
            cout<<"*"<<endl;
            perform(p+1, (s*arr[p])%101);
            if(c) {
                operators[p-2] = '*';
                return;
            }
            cout<<"+"<<endl;
            perform(p+1, (s+arr[p])%101);
            if(c) {
                operators[p-2] = '+';
                return;
            }
            cout<<"-"<<endl;
            perform(p+1, (s-arr[p])%101);
            if(c) {
                operators[p-2] = '-';
                return;
            }
        }
    }
}

int main() {
    freopen("D:/Code/untitled12/in.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
    }
    perform(2, arr[1]);
    cout<<arr[1];
    for(int i=0; i<n-1; i++) {
        cout<<operators[i]<<arr[i+2];
    }
    cout<<endl;
    return 0;
}
