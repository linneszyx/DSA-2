#include <bits/stdc++.h>
using namespace std;

int merging_process(vector<int> &arr, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;
    vector<int> temp;
    int count = 0;
    while (i <= m and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            count+=(m-i+1);
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
    return count;
}

int inversion_count(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    int c1 = inversion_count(arr, s, mid);
    int c2 = inversion_count(arr, mid + 1, e);
    int ci = merging_process(arr, s, e);
    return c1+c2+ci;
}
int main()
{
    vector<int> arr{0,5,2,3,1};
    int s = 0;
    int e = arr.size() - 1;
    cout<<inversion_count(arr, s, e)<<endl;
    return 0;
}  