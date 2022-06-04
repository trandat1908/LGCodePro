#include <bits/stdc++.h>
using namespace std;

/*int N;//The number of candidates
int A[100000 + 10];//Temperament value
//vector<pair<int,int>> vA;
int index1 = 9999999, index2 = 9999999;
int minA = 999999999;
int sum = 0;
int mid = -1;
bool flag = false;
void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin  >> A[i];
        if(!flag && A[i] >=0)
        {
            mid = i;
            flag = true;
        }
    }
}

int main(){
    freopen("D:/Code/PsychologyExperiment/input.txt","r",stdin);
    InputData();//	Input function


    int n = N-1;
    for(int j = 0; j<mid;j++)
    {
        if(minA == 0) break;
        int minB = 999999999;
        for(int k=n;k>=mid;k--)
        {
            if(minA == 0) break;
            sum = abs(A[j] + A[k]);
            if(sum <= minB)
            {
                minB = sum;
                if(minB < minA)
                {
                    n = k;
                    minA = minB;
                    index1 = j;
                    index2 = k;
                }

            }
            else
            {
                break;
            }

        }
    }
    cout << index1<< " "<<index2 <<endl;
    return 0;
}*/

int N;//The number of candidates
int A[100000 + 10];//Temperament value

void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

int main(){
    freopen("D:/Code/PsychologyExperiment/input.txt","r",stdin);
    InputData();//	Input function
    int sum;
    int i=0, j = N-1;
    int index1, index2;
    int minA = 999999999;
    while(i<j)
    {
        sum = A[i] + A[j];
        if(sum < 0)
        {
            sum = abs(sum);
            if(sum < minA)
            {
                minA = sum;
                index1 = i;
                index2 = j;
            }
            i++;
        }
        else if(sum >0)
        {
            sum = abs(sum);
            if(sum < minA)
            {
                minA = sum;
                index1 = i;
                index2 = j;
            }
            j--;
        }
        else
        {
            index1 = i;
            index2 = j;
            break;
        }
    }

    cout << index1 <<" "<<index2<<endl;
    return 0;
}
