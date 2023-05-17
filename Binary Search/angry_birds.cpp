#include <bits/stdc++.h>
using namespace std;
bool canPlaceBirds(int B, int N, vector<int> nest, int sep)
{
    int birds = 1;
    int loc = nest[0];
    for (int i = 1; i <= N - 1; i++)
    {
        int current_loc = nest[i];
        if (current_loc - loc >= sep)
        {
            birds++;
            loc = current_loc;
            if (birds == B)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int B = 3;
    vector<int> nest{1, 2, 4, 8, 9};
    int N = nest.size();
    sort(nest.begin(), nest.end());
    int s = 0;
    int ans = 0;
    int e = nest[N - 1] - nest[0];
    while (s <= e)
    {
        int m = (s + e) / 2;
        bool canPlace = canPlaceBirds(B, N, nest, m);
        if (canPlace)
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    cout << ans << endl;
    return 0;
}