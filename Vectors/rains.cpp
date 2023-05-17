/**
 * For each element in the array, we find the maximum height of bar from the left end up to an index i
 * in the array and store it in left array. From the right end, we traverse the array and find the
 * maximum height of bar from the right end up to an index i in the array and store it in right array.
 * Now, we traverse both arrays from left to right. While traversing left array from left to right, we
 * update ans: if height[i] is smaller than the smaller of left[i] and right[i], then add min(left[i],
 * right[i]) - height[i] to ans
 * 
 * @param height an array of integers representing the height of each bar
 * 
 * @return 6
 */
#include <bits/stdc++.h>
using namespace std;
int trappedwater(vector<int> height)
{
    int n = height.size();
    if (n <= 2)
        return 0;
    vector<int> left(n, 0), right(n, 0);
    left[0] = height[0];
    right[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], height[i]);
        right[n - i - 1] = max(right[n - i], height[n - i - 1]);
    }
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - height[i];
    }
    return water;
}
int main()
{
    vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trappedwater(water) << endl;
    return 0;
}