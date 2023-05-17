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
Node * insert(Node * root,int key){
    if(root==NULL) {
        return new Node(key);
    }
    if(key<root->key) {
        root->left = insert(root->left,key);
    }
    else {
        root->right = insert(root->right,key);
    }
    return root;
}
void printInOrder(Node * root) {
    if(root==NULL) return;
    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
}
Node * inOrderSuccessor(Node * root,Node * target) {
    if(target->right!=NULL) {
        Node * temp = target->right;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }
    Node * temp = root;
    Node * succ = NULL;
    while(temp!=NULL) {
        if(temp->key > target->key) {
            succ = temp;
            temp = temp->left;
        }
        else if(temp->key  < target->key)  {
            temp = temp->right;
        }
        else {
            break;
        }
    }
    return succ;
}
int main(){
    Node * root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(int x : arr){
        root = insert(root,x);
    }
    // printInOrder(root);
    Node * t1 = root->left->right->right;
    Node * t2 = root->right;
    cout<<"Inorder succ of 7 is : "<<inOrderSuccessor(root,t1)->key<<endl;
    cout<<"Inorder succ of 10 is : "<<inOrderSuccessor(root,t2)->key<<endl;
return 0;
}