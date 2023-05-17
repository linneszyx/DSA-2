#include <bits/stdc++.h>
using namespace std;
string keyPad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void printKeyPadOp(string ip, string op, int i = 0)
{
    if (ip[i] == '\0')
    {
        cout << op << endl;
        return;
    }
    int curr_digi = ip[i] - '0';
    if (curr_digi == 0 or curr_digi == 1)
        printKeyPadOp(ip, op, i + 1);
    for (int k = 0; k < keyPad[curr_digi].size(); k++)
    {
        printKeyPadOp(ip, op + keyPad[curr_digi][k], i + 1);
    }
    return;
}
int main()
{
    string ip;
    cin >> ip;
    string op;
    printKeyPadOp(ip, op);
    return 0;
}