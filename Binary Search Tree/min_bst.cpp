#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int key;
    Node *left;
    Node *right;
    Node(int key) {
        this->key = key;
        left =right = NULL;
    }
};
Node * sortedArrayBST(vector<int> arr,int start,int end){
    if(start>end) return NULL;
    int mid = (start+end)/2;
    Node * root = new Node(arr[mid]);
    root->left = sortedArrayBST(arr,start,mid-1);
    root->right = sortedArrayBST(arr,mid+1,end);
    return root;
}
void printInOrder(Node * root) {
    if(root==NULL) return;
    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
}

int main(){
    Node * root = NULL;
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int n = arr.size();
    root = sortedArrayBST(arr,0,n-1);
    printInOrder(root);
return 0;
}