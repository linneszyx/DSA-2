#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};
Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}
void printInOrder(Node *root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << root->key << " ";
    printInOrder(root->right);
}
int findClosetInBST(Node *root, int target)
{
    int closet;
    int diff = INT_MAX;
    Node *temp = root;
    while (temp != NULL)
    {
        int curr_diff = abs(temp->key - target);
        if (curr_diff == 0)
        {
            return temp->key;
        }
        if(curr_diff < diff) {
            diff = curr_diff;
            closet = temp->key;
        }
        if(temp->key  < target) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }
    return closet;
}
int main()
{
    Node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int x : arr)
    {
        root = insert(root, x);
    }
    // printInOrder(root);
    cout<<findClosetInBST(root,17)<<endl;
    return 0;
}