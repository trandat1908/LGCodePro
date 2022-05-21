//#include <bits/stdc++.h>
//using namespace std;

//int N; // Number of executable code data
//int M; // Number of virus data
//int A[20000 + 10]; // Executable code data
////int B[10 + 10]; // Virus data
//vector<int> B;
//int sol; // Correct answer
//vector<vector<int>> vPerOfB;
//void InputData(void)
//{
//    int i;

//    cin >> N >> M;

//    for (i = 0; i < N; i++) {
//        cin >> A[i];
//    }

//    for (i = 0; i < M; i++) {
//        int f;
//        cin>>f;
//        B.push_back(f);
//    }
//}

//void OutputData(void)
//{
//    cout << sol <<endl;
//}

//int Find(int i, int j)
//{
//    int div = A[i] - vPerOfB[j][0];
//    for (int k = 1; k < M; k++) {
//        if((A[i+k] - vPerOfB[j][k]) != div)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}

//void Solve(void)
//{
//    for(int i =0;i<=N-M;i++)
//    {
//        for(int j = 0; j < vPerOfB.size(); j++)
//        {
//            sol += Find(i,j);
//        }
//    }
//}


//void display(vector<int> a){
//    for(int i=0;i<M;i++) cout << a[i] << " ";
//    cout << endl;
//}
//void findPermutations(vector<int> b)
//{
//    sort(b.begin(), b.end());
//    do {
//        //display(b);
//        vPerOfB.push_back(b);
//    } while (next_permutation(b.begin(), b.end()));
//}

//int main(void)
//{
//    freopen("D:/Code/VirutTest/input.txt","r",stdin);
//    InputData(); // Input
//    findPermutations(B);
//    Solve(); // Problem solving

//    OutputData(); // Output

//    return 0;
//}
////12 3
////2 4 8 5 8 4 8 5 9 6 3 2
////4 8 5

#include <bits/stdc++.h>

using namespace std;

int N; // Number of executable code data
int M; // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10]; // Virus data

int sol; // Correct answer

void InputData(void)
{
    int i;

    cin >> N >> M;

    for (i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (i = 0; i < M; i++) {
        cin >> B[i];
    }
}

void OutputData(void)
{
    cout << sol <<endl;
}

int Find(int start)
{
    int i;
    vector<int> vA;
    for(int j = 0; j< M;j++)
    {
        vA.push_back(A[j + start]);
    }
    sort(vA.begin(),vA.end());
    int sub = vA[0] - B[0];
    for (i = 1; i < M; i++) {
        if (vA[i] - B[i] != sub) return 0;
    }
    return 1;
}

void Solve(void)
{
    int i;

    for (i = 0; i <= N - M; i++) {
        sol += Find(i);
    }
}

int main(void)
{
    freopen("D:/Code/VirutTest/input.txt","r",stdin);
    InputData(); // Input
    sort(B,B+M);
    Solve(); // Problem solving

    OutputData(); // Output

    return 0;
}
