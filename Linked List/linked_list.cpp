#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}
void insertAtMiddle(node *&head, int data, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, data);
    }
    else
    {
        node *temp = head;
        for (int jump = 1; jump <= pos - 1; jump++)
        {
            temp = temp->next;
        }
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}
void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}
node *recReverse(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *sHead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return sHead;
}
void reverse(node *&head)
{
    node *prev = NULL;
    node *current = head;
    node *temp;
    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
    return;
}
node *kReverse(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *prev = NULL;
    node *current = head;
    node *temp;
    int count = 1;
    while (current != NULL and count <= k)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        count++;
    }
    if (temp != NULL)
    {
        head->next = kReverse(temp, k);
    }
    return prev;
}
node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}
node * midPoint(node * head) {
    node * slow = head;
    node * fast = head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *mergeSort(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *mid = midPoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a, b);
}
int main()
{

    // node *a = NULL;
    // insertAtHead(a, 7);
    // insertAtHead(a, 10);
    // insertAtHead(a, 5);
    // insertAtHead(a, 1);
    // node *b = NULL;
    // insertAtHead(b, 6);
    // insertAtHead(b, 3);
    // insertAtHead(b, 2);
    // node *head = merge(a, b);
    // printLL(head);
    node *head = NULL;
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 9);
    head = mergeSort(head);
    printLL(head);
    // // printLL(head);
    // // head = recReverse(head);
    // printLL(head);
    // head = kReverse(head, 2);
    // printLL(head);
    return 0;
}