// https://www.hackerrank.com/challenges/minimum-loss/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<long,int>> mV;
    long p;
    for(int i=0; i<n; i++) {
        cin>>p;
        mV.push_back(make_pair(p, i));
    }
    sort(mV.begin(), mV.end());
    long res = 10e6;
    for(int i=0; i<n-1; i++) {
        if(mV[i+1].second<mV[i].second) {
            res = min(res, mV[i+1].first - mV[i].first);
        }
    }
    cout<<res<<endl;
    return 0;
}
