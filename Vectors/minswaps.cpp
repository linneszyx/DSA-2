#include <bits/stdc++.h>
using namespace std;
int countMinSwaps(vector<int> nums)
{
    int n = nums.size();
    int ans = 0;
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first = nums[i];
        ap[i].second = i;
    }
    sort(ap, ap + n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        int oldpos = ap[i].second;
        if (visited[i] == true or oldpos == i)
        {
            continue;
        }
        int node = 1;
        int cyc = 0;
        while (!visited[node])
        {
            visited[node] = true;
            int nextpos = ap[node].second;
            node = nextpos;
            cyc++;
        }
        ans += (cyc - 1);
    }
    return ans;
}
int main()
{
    vector<int> nums{5, 4, 3, 2, 1};
    cout << countMinSwaps(nums) << endl;
    return 0;
}