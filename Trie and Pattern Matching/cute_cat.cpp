#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool isTerminal;
    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }
    void insert(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                Node *n = new Node(ch);
                temp->children[ch] = n;
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }
};
void search_helper(Trie t,string doucment,int i,unordered_map<string,bool> &m){
    Node * temp = t.root;
    for(int j = i;j<doucment.length();j++){
        char ch = doucment[j];
        if(temp->children.count(ch)==0) {
            return;
        }
        temp = temp->children[ch];
        if(temp->isTerminal){
            string out = doucment.substr(i,j-i+1);
            m[out] = true;
        }
    }
    return;
}
void documentSearch(string doucment,vector<string> words){
    Trie t;
    for(auto w : words){
        t.insert(w);
    }
    unordered_map<string,bool> m;
    for(int i = 0 ;i<doucment.length();i++){
        search_helper(t,doucment,i,m);
    }
    for(auto w : words) {
        if(m[w]) {
            cout<<w <<" : True"<<endl;
        }
        else {
            cout<<w <<" : False"<<endl;
        }
    }
    
}
int main()
{   
    string doucment = "little cute cat loves to code in c++, java & python";
    vector<string> words = {
    "cute cat",
    "ttle",
    "cat",
    "quick",
    "big"
    };
    documentSearch(doucment,words);
    return 0;
}