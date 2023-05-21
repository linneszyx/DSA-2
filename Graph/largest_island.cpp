#include <bits/stdc++.h>
using namespace std;
#define in int
void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j, int &count){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0 || visited[i][j] == 1){
        return;
    }
    visited[i][j] = 1;
    count++;
    dfs(grid, visited, i+1, j, count);
    dfs(grid, visited, i-1, j, count);
    dfs(grid, visited, i, j+1, count);
    dfs(grid, visited, i, j-1, count);
}

int largest_island(vector<vector<int>> grid){
    in m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1 && visited[i][j] == 0){
                int count = 0;
                dfs(grid, visited, i, j, count);
                ans = max(ans, count);
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{1, 0, 0, 1, 0}, 
                                {1, 0, 1, 0, 0}, 
                                {0, 0, 1, 0, 1}, 
                                {1, 0, 1, 1, 1}, 
                                {1, 0, 1, 1, 0}};
    cout<<largest_island(grid)<<endl;
    return 0;
}