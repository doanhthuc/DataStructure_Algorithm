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

DouLinkedList *crateList(int x){
    DouLinkedList *l = new DouLinkedList;
    l->head = new node;
    l->head->data = x;
    l->head->pre = NULL;
    l->head->next = NULL;
    l->tail = l->head;
    return l;
}

DouLinkedList *addTail(DouLinkedList *l, int x){
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->pre = l->tail;
    l->tail -> next = temp;
    l->tail = temp;
    return l;
}

DouLinkedList *addHead(DouLinkedList *l, int x){
    node *temp = new node;
    temp->data = x;
    temp->next = l->head;
    temp->pre = NULL;
    l->head->pre = temp;
    l->head = temp;
    return l;
}

DouLinkedList *deleteHead(DouLinkedList *l){
    node *p = l->head->next;
    node *temp = l->head;
    p->pre = NULL;
    l->head = p;
    delete(temp);
    return l;
}

DouLinkedList *deleteTail(DouLinkedList *l){
    node *p = l->tail->pre;
    node *temp = l->tail;
    p->next = NULL;
    l->tail = p;
    delete(temp);
    return l;
}

DouLinkedList *deleteAt(DouLinkedList *l, int k){
    node *p = l->head;
    for (int i = 0; i < k-1; i++)
    {
        p = p->next;
    }
    node *temp = p->next;
    node *p2 = temp->next;
    p->next = p2;
    p2->pre = p;
    delete(temp);
    return l;
}

void printList(DouLinkedList *l){
    node *p =l->head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main(){
    int n, x, k;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    cout << "Nhap gia tri tai vi tri 0: ";
    cin >> x;
    DouLinkedList *l = crateList(x);
    for (int i = 1; i < n; i++)
    {
        cout << "Nhap phan tu tai vi tri " << i << ": ";
        cin >> x;
        l = addTail(l, x);
    }
    cout << "Nhap vi tri muon xoa: ";
    cin >> k;
    if (k == 0)
    {
        l = deleteHead(l);
    } else if (k == n-1)
    {
        l = deleteTail(l);
    }else{
        l = deleteAt(l, k);
    }
    printList(l);
    return 0;
}