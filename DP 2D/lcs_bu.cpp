#include <bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    // for (int i = 1; i <=n1; i++)
    // {
    //     for (int j = 1; j <= n2; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<char> res;
    int i = n1, j = n2;
    while (i != 0 and j != 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1])
        {
            j--;
        }
        else
        {
            res.push_back(s1[i - 1]);
            i--;
            j--;
        }
    }
    reverse(res.begin(), res.end());
    for (auto x : res)
    {
        cout << x << " ";
    }
    return dp[n1][n2];
}
int main()
{
    string s1 = "ABCD";
    string s2 = "ABEDG";
    cout << lcs(s1, s2);
    return 0;
}