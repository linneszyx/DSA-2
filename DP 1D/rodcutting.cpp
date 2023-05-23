#include<bits/stdc++.h>
using namespace std;
//recursive approach
int max_profit(int prices[],int n){
  if(n<=0){
    return 0;
  }
  int ans = INT_MIN;
  for(int i=0;i<n;i++){
    int cut = i+1;
    int current_ans = prices[i] + max_profit(prices,n-cut);
    ans = max(ans,current_ans);
  }
  return ans;
}
//bottom up approach
int max_profit_dp(int prices[],int n){
  int dp[n+1];
  dp[0] = 0;
  for(int i=1;i<=n;i++){
    int ans = INT_MIN;
    for(int j=0;j<i;j++){
      ans = max(ans,prices[j]+dp[i-j-1]);
    }
    dp[i] = ans;
  }
  return dp[n];
}
int main(){
  int prices[] = {1,5,8,9,10,17,17,20};
  int n = sizeof(prices)/sizeof(prices[0]);
  cout<<max_profit_dp(prices,n)<<endl;  
return 0;
}