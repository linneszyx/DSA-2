#include <bits/stdc++.h>
using namespace std;
bool divideAmongK(int arr[], int n, int k, int min_coins)
{
    int partitions = 0;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_sum + arr[i] >= min_coins)
        {
            partitions += 1;
            curr_sum = 0;
        }
        else
        {
            curr_sum += arr[i];
        }
    }
    return partitions >= k;
}
int k_partition(int
                    *arr,
                int n, int k)
{
    int s = 0;
    int e = 0;
    int ans;
    for (int i = 0; i < n; i++)
    {
        e += arr[i];
    }
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool isPossible = divideAmongK(arr, n, k, mid);
        if (isPossible)
        {
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int a[] = {1, 2, 3, 4};
    int n = sizeof(a) / sizeof(int);
    int k = 3;
    cout << k_partition(a, n, k) << endl;
    return 0;
}