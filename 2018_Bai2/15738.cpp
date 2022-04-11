#include <iostream>


int A[100001];
int B;
using namespace std;

void convert(int *arr,int &K,int I, int S)
{
    float mid = 0.0;
    if(I > 0)
    {
        mid = (I*1.0)/2;
        if(K <= mid || K <=I)
        {
            K = I - K + 1;
        }
    } 
    else
    {
        I = I * (-1);
        mid = S*1.0 - (I*1.0)/2;
        int c = S - I + 1;
        if((K <= mid && K >= c) || K > mid)
        {

            K = 2*mid - K + 1;    
        }
    }
    
}
int main()
{
    freopen("in.txt", "r", stdin);
    int N,K,M;
    cin >> N >> K >>M;
    for(int i=1;i<=N;i++)
    {
        cin >> A[i];
    }
    for(int i=0;i<M;i++)
    {
        cin>>B;
        convert(A,K,B, N);
    }

    cout<<K<<endl;

    return 0;
}