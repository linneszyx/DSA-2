#include <bits/stdc++.h>
using namespace std;
int largestband(vector<int> arr)
{
    int n = arr.size();
    int largestlen = 1;
    unordered_set<int> s;
    for (int x : arr)
    {
        s.insert(x);
    }
    for (auto ele : s)
    {
        int parent = ele - 1;
        if (s.find(parent) == s.end())
        {
            int next_no = ele + 1;
            int count = 1;
            while (s.find(next_no) != s.end())
            {
                next_no++;
                count++;
            }
            if (count > largestlen)
            {
                largestlen = count;
            }
        }
    }
    return largestlen;
}
int main()
{
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << largestband(arr) << endl;
    return 0;
}