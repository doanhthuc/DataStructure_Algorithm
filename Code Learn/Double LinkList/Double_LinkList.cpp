#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *pre;
};

struct Double_LinkList
{
    node *head;
    node *tail;
};

Double_LinkList *createList(int x){
    Double_LinkList *l = new Double_LinkList;
    l -> head = new node;
    l -> head -> data = x;
    l -> head -> pre = NULL;
    l -> head -> next = NULL;
    l -> tail = l -> head;
    return l;
}

Double_LinkList *addHead(Double_LinkList *l, int x){
    node *temp = new node;
    temp -> data = x;
    temp -> pre = NULL;
    temp -> next = l -> head;
    l -> head -> pre = temp;
    l -> head = temp;
    return l;
}

Double_LinkList *addTail(Double_LinkList *l, int x){
    node *temp = new node;
    temp -> data = x;
    temp -> next = NULL;
    temp -> pre = l -> tail;
    l -> tail -> next = temp;
    l -> tail = temp;
    return l;
}

void prinList(Double_LinkList *l){
    node *p = l -> head;
    while (p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
}

int main(){
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    Double_LinkList *l = createList(1);
    for (int i = 2; i <= n; i++)
    {
        l = addHead(l, i);
        l = addTail(l, i);
    }
    prinList(l);
    return 0;
}

