#include <bits/stdc++.h>
using namespace std;
string unique_substring(string str)
{
    int i = 0;
    int j = 0;
    int window_len = 0;
    int max_window_len = 0;
    int start_window = -1;
    unordered_map<char, int> m;
    while (j < str.length())
    {
        char ch = str[j];
        // if it is inside hashmap and its index >= start of the current window
        if (m.count(ch) and m[ch] >= i)
        {
            // update the start of the window
            i = m[ch] + 1;
            // update the window length
            window_len = j - i;
        }
        // update the last occurence
        m[ch] = j;
        window_len++;
        j++;
        // update max window length at every step
        if (window_len > max_window_len)
        {
            max_window_len = window_len;
            start_window = i;
        }
    }
    return str.substr(start_window, max_window_len);
}
int main()
{
    string input;
    cin >> input;
    cout << unique_substring(input) << endl;
    return 0;
}
