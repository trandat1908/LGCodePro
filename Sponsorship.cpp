#include <iostream>
using namespace std;

int N;//Number of sponsored goods
int sol = -30001;//Maximum preference of the first method
int tmp;

void Solve(){
 cin >> N;
 int sum = 0;
 for(int i=0;i<N;i++){
  cin >> tmp;
  sum += tmp;
  if (sum > sol) sol = sum;
  if (sum < 0) sum = 0;
 }
}

int main(){
 Solve();
 cout << sol << endl;//Output
 return 0;
}
