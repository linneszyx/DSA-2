#include <bits/stdc++.h>
using namespace std;
/**
 * We sort the array, and then iterate through the array, and for each element, we use two pointers to
 * find the other two elements that sum up to the target
 * 
 * @param arr The array of integers
 * @param sum The sum of the triplet.
 * 
 * @return A vector of vectors of ints.
 */
vector<vector<int>> triplets(vector<int> arr, int sum)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int n = arr.size();
    for (int i = 0; i <= n - 3; i++)
    {
        int j = i + 1;
        int k = n - 1;
        // two pointer
        while (j < k)
        {
            int curr_sum = arr[i];
            curr_sum += arr[j];
            curr_sum += arr[k];
            if (curr_sum == sum)
            {
                res.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (curr_sum > sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return res;
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int s = 18;
    auto result = triplets(arr, s);
    for (auto v : result)
    {
        for (auto n : v)
        {
            cout << n << ",";
        }
        cout << endl;
    }
    return 0;
}