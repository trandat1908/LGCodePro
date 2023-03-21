// https://codeforces.com/problemset/problem/1744/C

#include <bits/stdc++.h>

using namespace std;
int t, n;
char c;
string s;
int main()
{
    //freopen("D:/Code/TrafficLight/in.txt","r",stdin);
    cin>>t;
    while(t--) {
        cin>>n>>c;
        cin>>s;
        if(c=='g') {
            cout<<0<<endl;
        } else if(c=='r') {
            int ans = 0;
            bool isR = false;
            bool isG = false;
            int posR = 0;
            int posG = 0;
            int firstPosG = 0;
            bool saveFirPosG = false;
            for(int i=0; i<n; i++) {
                if(s[i]=='r') {
                    if(isR==false) {
                        posR = i;
                        isR = true;
                        isG = false;
                    }
                } else if(s[i]=='g') {
                    if(saveFirPosG==false) {
                        firstPosG = i;
                        saveFirPosG = true;
                    }
                    if(isG==false) {
                        if(isR==true) {
                            posG = i;
                            ans = max(posG - posR,ans);
                            isR = false;
                        }
                        isG = true;
                    }
                }
            }
            if(isR) {
                ans = max(ans, n-posR+firstPosG);
            }
            cout<<ans<<endl;
        } else {
            int ans = 0;
            bool isY = false;
            bool isG = false;
            int posY = 0;
            int posG = 0;
            int firstPosG = 0;
            bool saveFirPosG = false;
            for(int i=0; i<n; i++) {
                if(s[i]=='y') {
                    if(isY==false) {
                        posY = i;
                        isY = true;
                        isG = false;
                    }
                } else if(s[i]=='g') {
                    if(saveFirPosG==false) {
                        firstPosG = i;
                        saveFirPosG = true;
                    }
                    if(isG==false) {
                        if(isY==true) {
                            posG = i;
                            ans = max(posG - posY,ans);
                            isY = false;
                        }
                        isG = true;
                    }
                }
            }
            if(isY) {
                ans = max(ans, n-posY+firstPosG);
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}
