#include <bits/stdc++.h>
using namespace std;
// O*(k^n)
int countWays(int n, int k)
{
    int ans = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    for (int jump = 1; jump <= k; jump++)
    {
        ans += countWays(n - jump, k);
    }
    return ans;
}
// Top Down O(n,k)
int countWaystd(int n, int k, int *dp)
{
    int ans = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != 0)
        return dp[n];

    for (int jump = 1; jump <= k; jump++)
    {
        ans += countWaystd(n - jump, k, dp);
    }
    return dp[n] = ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int dp[100] = {0};
    cout << countWays(n, k) << endl;
    cout << countWaystd(n, k, dp) << endl;
    return 0;
}