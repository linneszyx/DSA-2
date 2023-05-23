#include <bits/stdc++.h>
using namespace std;
int wines(int prices[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j) dp[i][j] = prices[i]*n;
            else if (i < j)
            {
                int year = n - (j - i);
                int pick_left = prices[i] * year + dp[i + 1][j];
                int pick_right = prices[j] * year + dp[i][j - 1];
                dp[i][j] = max(pick_left, pick_right);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[0][n - 1];
}
int main()
{
    int arr[] = {2, 3, 5, 1, 4};
    int n = 5;
    cout << wines(arr, n) << endl;
    return 0;
}