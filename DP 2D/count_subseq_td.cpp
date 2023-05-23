#include <bits/stdc++.h>
using namespace std;
int countSubseq(string a, string b, int m, int n)
{
    if ((m == -1 and n == -1) or n == -1)
        return 1;
    if (m == -1)
        return 0;
    if (a[m] == b[n])
    {
        return countSubseq(a, b, m - 1, n - 1) + countSubseq(a, b, m - 1, n);
    }
    return countSubseq(a, b, m - 1, n);
}
int main()
{
    string a = "ABCECDG";
    string b = "ABC";
    cout << countSubseq(a, b, a.size() - 1, b.size() - 1) << endl;
    return 0;
}