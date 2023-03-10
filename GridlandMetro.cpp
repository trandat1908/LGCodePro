//https://github.com/trandat1908/LGCodePro/new/main
#include <bits/stdc++.h>

using namespace std;

long n, m;
int k;
long n1, n2, n3, n4;
long m1, m2, m3, m4;


int main() {
    cin>>n>>m>>k;
    
    long r, c1, c2;
    unordered_map<long, vector<pair<long,long>>> uMap;
    long s = 0;
    for(int i=0; i<k; i++) {
        cin>>r>>c1>>c2;  
        if(uMap.find(r) == uMap.end()) {
            vector<pair<long,long>> mVec;
            mVec.push_back(make_pair(c1, c2));
            uMap[r] =  mVec;
        } else {
            uMap[r].push_back(make_pair(c1, c2));
            sort(uMap[r].begin(), uMap[r].end());
            vector<pair<long,long>> mVec;
            long mStart = uMap[r][0].first;
            long mEnd = uMap[r][0].second;
            for(int k=1; k<uMap[r].size(); k++) {
                if(uMap[r][k].first<=mEnd) {
                    
                    mEnd = max(uMap[r][k].second, mEnd);
                } else {
                    mVec.push_back(make_pair(mStart, mEnd));
                    mStart = uMap[r][k].first;
                    mEnd = uMap[r][k].second;   
                }
            }
            mVec.push_back(make_pair(mStart, mEnd));
            uMap[r].clear();
            uMap[r] = mVec;
        } 
    }
    
    unordered_map<long, vector<pair<long,long>>>::iterator it;
    
    for(it = uMap.begin(); it != uMap.end(); it++) {
        for(int a =0; a<it->second.size(); a++) {
            s += it->second[a].second - it->second[a].first +1;
        }
    }
    long long f = m*n;
    long long ans = f-s;
    cout<<ans<<endl;
    return 0;
}
