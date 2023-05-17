#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;
    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};
class SuffixTrie
{
public:
    Node *root;
    SuffixTrie()
    {
        root = new Node('\0');
    }
    void insert_helper(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    bool search(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
    void insert(string word) {
        for(int i = 0;word[i]!='\0';i++){
            insert_helper(word.substr(i));
        }
    }
};
int main()
{
    string input = "hello";
    string suffixes[] = {
        "lo",
        "ell",
        "hello"
    };
    SuffixTrie st;
    st.insert(input);
    for(auto sf : suffixes) {
        if(st.search(sf)) {
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}