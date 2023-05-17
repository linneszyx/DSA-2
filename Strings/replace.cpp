#include<bits/stdc++.h>
using namespace std;
void replacespace(char *str){
    int space = 0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            space++;
        }
    }
    int index = strlen(str) + space*2;
    str[index] = '\0';
    for(int i=strlen(str)-1;i>=0;i--){
        if(str[i]==' '){
            str[index-1] = '0';
            str[index-2] = '2';
            str[index-3] = '%';
            index = index - 3;
        }
        else{
            str[index-1] = str[i];
            index--;
        }
    }

}
int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacespace(input);
    cout << input << endl;
return 0;
}