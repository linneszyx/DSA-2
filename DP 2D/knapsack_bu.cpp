#include<bits/stdc++.h>
using namespace std;
//bottom up approach
int knapsack(int wts[],int prices[],int N,int W){
  vector<vector<int>> dp(N+1,vector<int>(W+1,0));
    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            int inc=0,exc=0;
            if(wts[n-1]<=w){
                inc=prices[n-1]+dp[n-1][w-wts[n-1]];
            }
            exc=dp[n-1][w];
            dp[n][w]=max(inc,exc);
        }
    }
    return dp[N][W];
}

int main(){
    int wts[]={2,7,3,4};
    int prices[]={5,20,20,10};
    int N=4;
    int W=11;
    cout<<knapsack(wts,prices,N,W)<<endl;
return 0;
}