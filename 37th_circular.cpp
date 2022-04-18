// Implement a circular linked list and print its elements(this code does this)
// insert front 
// insert last(this code does this)
// insert at a specific position
// delete front 
// delete last
// delete at a specific position
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=nullptr;
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
        head->next=head;
    }
    else
    {
        node *p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        temp->next=head;
        p->next=temp;
    }
    return head;
}
void display(node *head)
{
    if(head!=nullptr)
    {
        cout<<head->data<<" ";
        node *p=head->next;
        while(p!=head)
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
    cout<<"Enter number of nodes : ";
    cin>>n;
    node *head=nullptr;
    while(n--)
    {
        head=append(head);
    }
    display(head);
}