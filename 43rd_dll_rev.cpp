//reverse a DOUBLY linked list (reversing links)
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data=x;
        next=nullptr;
        prev=nullptr;
    }
};

node *append(node *head)
{
    int data;
    cout<<"Enter data : ";
    cin>>data;
    node *temp=new node(data);
    if(head==nullptr)
    {
        head=temp;
    }
    else 
    {
        node *p=head;
        while(p->next!=nullptr)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }
    return head;
}
void display(node *head)
{
    if(head!=nullptr)
    {
        node *p=head;
        while(p!=nullptr)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }
    else
    cout<<"Empty list.";
}
int main()
{
    int n;
    cout<<"Enter no. of nodes. : ";
    cin>>n;
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=append(head);

    node *p=head;
    while(p!=nullptr)
    {
        node *temp=p->next;
        p->next=p->prev;
        p->prev=temp;

        if(p->prev==nullptr)
        head=p;//making the new head

        p=p->prev;//since we have reversed the links so we need to traverse to the previous node if we want to travel ahead

    }
    display(head);
}