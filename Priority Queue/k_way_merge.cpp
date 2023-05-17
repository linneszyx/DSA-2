#include <bits/stdc++.h>
using namespace std;
vector<int> mergeKArrays(vector < vector<int>> arr)
{
    int k = arr.size();
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
    vector<int> op;
    for(int i = 0;i<k;i++) {
        int element = arr[i][0];
        q.push({element,i,0});
    }
    while(!q.empty()){
        auto top = q.top();
        q.pop();
        int element = top[0];
        int arr_idx = top[1];
        int ele_idx = top[2];
        op.push_back(element);
        if(ele_idx + 1 < arr[arr_idx].size()) {
            int next_element = arr[arr_idx][ele_idx+1];
            q.push({next_element,arr_idx,ele_idx+1});
        }
    }
    return op;
}
int main()
{
    vector<vector<int>> arr = {{10, 15, 20, 30},
                               {2, 5, 8, 14, 24},
                               {0, 11, 60, 90}};
    vector<int> result = mergeKArrays(arr);
    for (auto x : result)
    {
        cout << x << " ";
    }
    return 0;
}