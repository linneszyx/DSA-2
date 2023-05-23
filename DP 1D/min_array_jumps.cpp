#include <bits/stdc++.h>
using namespace std;
int min_jumps(vector<int> arr, int n, vector<int> dp, int i)
{
    if (i == n - 1)
        return 0;
    if (i >= n)
        return INT_MAX;
    if (dp[i] != 0)
        return dp[i];
    int steps = INT_MAX;
    int maxjump = arr[i];
    for (int jump = 1; jump <= maxjump; jump++)
    {
        int next_Cell = i + jump;
        int subprob = min_jumps(arr, n, dp, next_Cell);
        if (subprob != INT_MAX)
        {
            steps = min(steps, subprob + 1);
        }
    }
    return dp[i]=steps;
}
int main()
{
    vector<int> arr{3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    int n = arr.size();
    vector<int> dp(n, 0);
    cout << min_jumps(arr, n, dp, 0) << endl;
    return 0;
}