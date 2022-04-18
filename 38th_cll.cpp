// Implement a circular linked list and print its elements
// insert front (this code does this)
// insert last
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

node *first_node_created=nullptr;/*
stores the address of first ever node created so that I won't have to traverse till last
node to link first node
*/

node *insert_front(node *head)
{
    int data;
    cout<<"Enter data : ";
    cin>>data;
    node *temp=new node(data);
    if(head==nullptr)
    {
        head=temp;
        head->next=head;
        first_node_created=head;
    }
    else
    {
        temp->next=head;
        head=temp;
        first_node_created->next=temp;
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
        head=insert_front(head);
    }
    display(head);
}