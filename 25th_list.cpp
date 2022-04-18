//insert front of a linked list
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int a)//constructor for structure
    {
        data=a;
        next=nullptr;
    }
    
};
node *insert_front(node *head)//function to insert a new node at the beginning of the node
{
    int a;
    cout<<"Enter the number : ";
    cin>>a;
    node *temp=new node(a);
    if(head==nullptr)
    head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
    return head;
}
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=insert_front(head);
    node *p=head;
    while(p!=nullptr)
    {
        cout<<p->data<<" --> ";
        p=p->next;
    }
}