#include<bits/stdc++.h>
using namespace std;
vector<int> pairSum(vector<int>arr,int s){
    unordered_set<int> ss;
    vector<int> res;
    for(int i=0;i<arr.size();i++){
        int x = s - arr[i];
        if(ss.find(x)!=ss.end()){
            res.push_back(x);
            res.push_back(arr[i]);
            return res;
    }
    ss.insert(arr[i]);
    }
    return {};
}
int main()
{
    vector<int> arr{10,5,2,3,-6,9,11};
    int s = 4;
    auto p = pairSum(arr,s);
    if(p.size()==0){
        cout<<"No such pair\n";
    }
    else{
        cout<<p[0]<<","<<p[1]<<endl;
    }
return 0;
}