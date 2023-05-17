#include<bits/stdc++.h>
using namespace std;
int main()
{
    char input[10000];
    cin.getline(input, 10000);
    cout<<strtok(input, " ")<<endl;
    while(strtok(NULL, " ")!=NULL){
        cout<<strtok(NULL, " ")<<endl;
    }
return 0;
}