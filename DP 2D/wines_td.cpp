#include<bits/stdc++.h>
using namespace std;
int wines(int dp[][10],int arr[],int L,int R,int year){
  if(L>R){
    return 0;
  }
  if(dp[L][R]!=0){
    return dp[L][R];
  }
  int op1 = arr[L]*year + wines(dp,arr,L+1,R,year+1);
  int op2 = arr[R]*year + wines(dp,arr,L,R-1,year+1);
  return dp[L][R] = max(op1,op2);
}
int main(){
  int arr[] = {2,3,5,1,4};
  int n = 5;
  int dp[10][10] = {0};
  cout<<wines(dp,arr,0,n-1,1)<<endl;  
return 0;
}