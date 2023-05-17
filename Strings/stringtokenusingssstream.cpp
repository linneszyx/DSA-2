#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    vector<string> tokens;
    while(getline(ss, word, ' ')){
        tokens.push_back(word);
    }
    for(auto token: tokens){
        cout << token << ",";
    }
return 0;
}