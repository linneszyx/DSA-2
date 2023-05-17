#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;
    vector<int> temp;
    while (i <= m and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
   
    while (i <= m)
    {
        temp.push_back(arr[i++]);
    }

    while (j <= e)
    {
        temp.push_back(arr[j++]);
    }

    int index = 0;
    for (int idx = s; idx <= e; idx++)
    {
        arr[idx] = temp[index++];
    }
    return;
}

void mergeSort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    return merge(arr, s, e);
}
int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 8};
    int s = 0;
    int e = arr.size() - 1;
    mergeSort(arr, s, e);
    for (int x : arr)
    {
        cout << x << ",";
    }
    cout<<endl;
    return 0;
}