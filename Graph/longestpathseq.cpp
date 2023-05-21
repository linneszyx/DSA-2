#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> matrix, vector<vector<bool>> &visited, vector<vector<int>> &cache, int i, int j, int m, int n)
{
    visited[i][j] = true;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int cnt = 0;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j])
        {
            int subProblemCount = 0;
            if (visited[x][y])
            {
                cnt = max(cnt, 1 + cache[x][y]);
            }
            else
            {
                dfs(matrix, visited, cache, x, y, m, n);
                cnt = max(cnt, 1 + cache[x][y]);
            }
        }
    }
    cache[i][j] = cnt;
    return;
}
int longestPathSequence(vector<vector<int>> matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> cache(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                dfs(matrix, visited, cache, i, j, m, n);
                ans = max(ans, cache[i][j]);
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 9}, {5, 3, 8}, {4, 6, 7}};
    cout << longestPathSequence(matrix);
    return 0;
}