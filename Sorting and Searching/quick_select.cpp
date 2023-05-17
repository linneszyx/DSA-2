#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &array1, int s, int e)
{
    int pivot = array1[e];
    int i = s - 1;
    for (int j = s; j <= e; j++)
    {
        if (array1[j] < pivot)
        {
            i++;
            swap(array1[i], array1[j]);
        }
    }
    swap(array1[i + 1], array1[e]);
    return i + 1;
}
int quickselect(vector<int> &array1, int s, int e, int k)
{
    int p = partition(array1, s, e);
    if (p == k)
        return array1[p];
    else if (k < p)
        return quickselect(array1, s, p - 1, k);
    else
        return quickselect(array1, p + 1, e, k);
}
int main()
{
    vector<int> array1{10, 5, 2, 0, 7, 6, 4};
    int n = array1.size();
    int k;
    cin >> k;
    cout<<quickselect(array1, 0, n - 1, k)<<endl;
    return 0;
}