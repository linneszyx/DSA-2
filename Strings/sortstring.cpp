#include <bits/stdc++.h>
using namespace std;
bool lexicographicalCompare(pair<string, string> p1, pair<string, string> p2)
{
    return p1.first < p2.first;
}
bool numericeCompare(pair<string, string> p1, pair<string, string> p2)
{
    int n1 = stoi(p1.first);
    int n2 = stoi(p2.first);
    return n1 < n2;
}
string extractStringToken(string str, int key)
{
    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}
int main()
{
    int n;
    cin >> n;
    cin.get();
    string temp;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        v.push_back(temp);
    }
    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;
    vector<pair<string, string>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({extractStringToken(v[i], key), v[i]});
    }
    if (ordering == "numeric")
    {
        sort(vp.begin(), vp.end(), numericeCompare);
    }
    else
    {
        sort(vp.begin(), vp.end(), lexicographicalCompare);
    }
    if (reversal == "true")
    {
        reverse(vp.begin(), vp.end());
    }
    for (int i = 0; i < n; i++)
    {
        cout << vp[i].second << endl;
    }
    return 0;
}