//implement Doubly Linked List insert front
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

node *insert_front(node *head)
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
        temp->next=head;
        head->prev=temp;
        head=temp;
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
    head=insert_front(head);
    display(head);
}