#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
// IP : 1 2 4  -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
node *levelOrderBuild()
{
    int d;
    cin >> d;
    node *root = new node(d);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            current->left = new node(c1);
            q.push(current->left);
        }
        if (c2 != -1)
        {
            current->right = new node(c2);
            q.push(current->right);
        }
    }
    return root;
}
void levelOrderPrint(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *t = q.front();
        if (t == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout << t->data << " ";
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
    }
}
int height(node *root)
{
    if (root == NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
}
int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int D1 = height(root->left) + height(root->right);
    int D2 = height(root->left);
    int D3 = height(root->right);
    return max(D1, max(D2, D3));
}
class HDPair
{
public:
    int height;
    int diameter;
};
HDPair opDiameter(node *root)
{
    HDPair p;
    if (root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }
    HDPair left = opDiameter(root->left);
    HDPair right = opDiameter(root->right);
    p.height = max(left.height, right.height) + 1;
    int d1 = left.height + right.height;
    int d2 = left.diameter;
    int d3 = right.diameter;
    p.diameter = max(d1, max(d2, d3));
    return p;
}
int replaceWithSum(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL and root->right == NULL)
        return root->data;
    int ls = replaceWithSum(root->left);
    int rs = replaceWithSum(root->right);
    int temp = root->data;
    root->data = ls + rs;
    return temp + root->data;
}
pair<int, bool> isHeightBalanced(node *root)
{

    pair<int, bool> p, Left, Right;
    if (root == NULL)
    {
        p.first = 0;
        p.second = true;
        return p;
    }
    Left = isHeightBalanced(root->left);
    Right = isHeightBalanced(root->right);
    int height = max(Left.first, Right.first) + 1;
    if (abs(Left.first - Right.first) <= 1 and Left.second and Right.second)
    {
        return make_pair(height, true);
    }
    return make_pair(height, false);
}
class Pair
{
public:
    int inc;
    int exec;
};
Pair maxSubsetSum(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.inc = p.exec = 0;
        return p;
    }
    Pair left = maxSubsetSum(root->left);
    Pair right = maxSubsetSum(root->right);
    p.inc = root->data + left.exec + right.exec;
    p.exec = max(left.inc, left.exec) + max(right.inc, right.exec);
    return p;
}
void printAtLevelK(node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data <<" ";
        return;
    }
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
    return;
}
int printNodesAtDistance(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printAtLevelK(target, k);
        return 0;
    }
    int DL = printNodesAtDistance(root->left, target, k);
    if (DL != -1)
    {
        if (DL + 1 == k)
        {
            cout << root->data<<" ";
        }
        else {
            printAtLevelK(root->right,k-2-DL);
        }
        return 1 + DL;
    }
    int DR = printNodesAtDistance(root->right, target, k);
    if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data<<" ";
        }
        else {
            printAtLevelK(root->left,k-2-DR);
        }
        return 1 + DR;
    }
    return -1;
}
void traverseTree(node *tree,int d,map<int,vector<int>> &m){
    if(tree==NULL) return;
    m[d].push_back(tree->data);
    traverseTree(tree->left,d-1,m);
    traverseTree(tree->right,d+1,m);
}
void verticalPrint(node * root){
    map<int,vector<int>> m;
    int d = 0;
    traverseTree(root,d,m);
    for(auto p : m) {
        int key = p.first;
        vector<int> line = p.second;
        for(auto data : line) {
            cout<<data<<" ";
        }
        cout<<endl;
    }
    return;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->left->right->right->left = new node(9);
    root->left->right->right->right = new node(10);
    node *target = root->left->right;
    // int k = 2;
    // printNodesAtDistance(root, target, k);
    // cout<<endl;
    verticalPrint(root);
    // pair<int,bool> p = isHeightBalanced(root);
    // if(p.second) {
    //     cout<<"Yes, it is height balanced ";
    // }
    // else {
    //     cout<<"Not a height balanced tree ";
    // node *root = buildTree();
    // node *root = levelOrderBuild();
    // levelOrderPrint(root);
    // cout<<"Diameter is " <<diameter(root)<<endl;
    // replaceWithSum(root);
    // levelOrderPrint(root);
    // Pair p = maxSubsetSum(root);
    // cout<<"Max Sum : "<<max(p.inc,p.exec)<<endl;

    return 0;
}