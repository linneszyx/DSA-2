#include<bits/stdc++.h>
using namespace std;
void subseq(string s,string o,vector<string> &v){
    if(s.size()==0){
        v.push_back(o);
        return;
    }
  /* Taking the first character of the string and then taking the rest of the string. */
    char ch = s[0];
    string ros = s.substr(1);
    subseq(ros,o+ch,v);
    subseq(ros,o,v);
}
bool compare(string s1,string s2){
    if(s1.length()==s2.length()){
        return s1<s2;
    }
    return s1.length()<s2.length();
}
int main()
{
    string s;
    cin>>s;
    vector<string> v;
    string output = "";
    subseq(s,output,v);
    sort(v.begin(),v.end(),compare);
return 0;
}