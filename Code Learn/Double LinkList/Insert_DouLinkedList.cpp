#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *pre;
};

struct DouLinkedList
{
    node *head;
    node *tail;
};

DouLinkedList *createList(int x){
    DouLinkedList *l = new DouLinkedList;
    l -> head = new node;
    l -> head -> data = x;
    l -> head -> pre = NULL;
    l -> head -> next = NULL;
    l -> tail = l -> head;
    return l;
}

DouLinkedList *addHead(DouLinkedList *l, int x){
    node *temp = new node;
    temp -> data = x;
    temp -> pre = NULL;
    temp -> next = l -> head;
    l -> head -> pre = temp;
    l -> head = temp;
    return l;
}

DouLinkedList *addTail(DouLinkedList *l, int x){
    node *temp = new node;
    temp -> data = x;
    temp -> next = NULL;
    temp -> pre = l -> tail;
    l -> tail -> next = temp;
    l -> tail = temp;
    return l;
}

DouLinkedList *addAt(DouLinkedList *l, int k, int x){
    node *p = l -> head;
    for (int i = 0; i < k-1; i++)
    {
        p = p ->next;
    }
    node *temp = new node;
    temp -> data = x;
    temp -> pre = p;
    temp -> next = p -> next;
    p -> next -> pre = temp;
    p -> next = temp;
    return l;
}

void printList(DouLinkedList *l){
    node *p = l -> head;
    while (p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
}

int main(){
    int n, x, k;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    cout << "Nhap gia tri cua phan tu: ";
    cin >> x;
    DouLinkedList *l = createList(x);
    for (int i = 1; i < n; i++)
    {
        cout << "Nhap phan tai vi tri " << i << ": ";
        cin >> x;
        l = addTail(l, x);
    }
    cout << "Nhap gia tri muon chen: ";
    cin >> x;
    cout << "Nhap vi tri muon chen: ";
    cin >> k;
    if (k == 0)
    {
        l = addHead(l, x);
    } else if (k == n)
    {
        l = addTail(l, x);
    }else {
        l = addAt(l, k, x);
    }
    printList(l);
    return 0;
}
