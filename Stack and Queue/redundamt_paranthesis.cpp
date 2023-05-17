#include <bits/stdc++.h>
using namespace std;
bool checkRedundant(string str)
{
    stack<char> s;
    for (char ch : str)
    {
        if (ch != ')')
        {
            s.push(ch);
        }
        else
        {
            bool operater_found = false;
            while (!s.empty() and s.top() != '(')
            {
                char top = s.top();
                if (top == '+' or top == '-' or top == '*' or top == '/')
                {
                    operater_found = true;
                }
                s.pop();
                if (operater_found == false)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    string str = "((a+b)+c)";
    if (checkRedundant(str))
    {
        cout << "Contains Redundant Paranthesis";
    }
    else
    {
        cout << "Not Contains Redundant Paranthesis";
    }
    return 0;
}