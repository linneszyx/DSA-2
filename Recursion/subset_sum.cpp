#include <bits/stdc++.h>
using namespace std;
int countSubSets(vector<int> arr, int n, int i, int X)
{
    if (i == n)
    {
        if (X == 0)
        {
            return 1;
        }
        return 0;
    }
    int inc = countSubSets(arr, n, i + 1, X - arr[i]);
    int exc = countSubSets(arr, n, i + 1, X);
    return inc + exc;
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    int sum = 6;
    cout << countSubSets(arr,arr.size(),0,sum)<<endl;
    return 0;
}