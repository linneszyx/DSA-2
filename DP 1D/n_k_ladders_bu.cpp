#include <bits/stdc++.h>
using namespace std;
//Bottom Up O(n,k)
int countWaysbu(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <=n; i++)
    {
        for (int jump = 1; jump <= k; jump++)
        {
            if (i - jump >= 0)
                dp[i] += dp[i - jump];
        }
    }
    return dp[n];
}
//Bottom Up O(n+k) space optimized
int countWayOpt(int n,int k){
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;
    for(int i=2;i<=k;i++){
            dp[i]=2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++){
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }
    return dp[n];
}
int main()
{
    int n, k;
    cin >> n >> k;
    int dp[100] = {0};
    cout << countWaysbu(n, k) << endl;
    cout<<countWayOpt(n,k)<<endl;
    return 0;
}