#include <iostream>
using namespace std;

int N;//Number of mushrooms
int P[150000 + 10];//Mushroom value
int ans = 0;
void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> P[i];
    }
    P[N] = 0;
}

int main(){

    //freopen("D:/Code/MarioGame/input.txt","r",stdin);
    InputData();			//	Input function

    //Solve();
    //ans+=P[0];
    int min=999;
    int max=-999;
    int check = 1;
    if(N == 1)
    {
        ans+=P[0];
    }
    else
    {
        if(P[0] > P[1])
        {
            ans+=P[0];
            check = 1;
        }
        else
        {
            check = 0;
        }
        for(int i=1;i<=N;i++)
        {
            if((P[i] < P[i-1]))
            {
                min = P[i];
                if(check == 0)
                {
                    ans+=max;
                    check = 1;
                }

                max = -999;
            }
            else if((P[i] >= P[i-1]))
            {
                if(check == 1)
                {
                    ans-=min;
                    check = 0;
                }
                max = P[i];
                min = 999;
            }
        }
    }



    cout << ans << endl;	//	Output answer
    return 0;
}
