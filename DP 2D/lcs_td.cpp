#include <bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == s1.length() || j == s2.length())
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
    }
    int op1 = lcs(s1, s2, i + 1, j, dp);
    int op2 = lcs(s1, s2, i, j + 1, dp);
    return dp[i][j] = max(op1, op2);
}
int main()
{
    string s1 = "ABCD";
    string s2 = "ABEDG";
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    cout << lcs(s1, s2, 0, 0, dp);
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}