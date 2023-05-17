#include <bits/stdc++.h>
using namespace std;
void generate_brackets(string op, int n, int open, int close, int i)
{
    if (i == 2 * n)
    {
        cout << op << endl;
        return;
    }
    if (open < n)
    {
        generate_brackets(op + '(', n, open + 1, close, i + 1);
    }
    if (close < open)
    {
        generate_brackets(op + ')', n, open, close + 1, i + 1);
    }
}
int main()
{
    string op;
    int n;
    cin >> n;
    generate_brackets(op, n, 0, 0, 0);
    return 0;
}