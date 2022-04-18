// Implement a circular linked list and print its elements
// insert front 
// insert last 
// insert at a specific position 
// delete front (this code does this)
// delete last (this code does this)
// delete at a specific position (this code does this)
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
node *delete_pos(node *head)
{   
    int pos;
    cout<<"Enter the position you want to delete : ";
    cin>>pos;
    if(pos==1)//if it is the first node to delete
    {
        node *old_head=head;
        head=head->next;
        node *p=head;
        while(p->next!=old_head)
        p=p->next;
        p->next=head;
    }
    else
    {
        /*
        either it can be any node in middle 
        or
        it can be the last node 
        so we will have to handle two cases.
        */
       int ind=2;
       int flag=0;
       node *prev=head;
       node *curr=head->next;
       while(curr->next!=head)//dlt in middle 
       {
           if(ind==pos)
           {
               prev->next=curr->next;
               curr->next=nullptr;
               delete curr;
               flag=1;
               break;
           }
           ind++;
           prev=curr;
           curr=curr->next;
       }
       if(flag==0 && pos==ind)//dlt last
       {
           prev->next=head;
           delete curr;
       }

    }
    return head;
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
    while(1)
    {
        int ch;
        cout<<"Press 1 to delete at any position or any key to exit : ";
        cin>>ch;
        cout<<"\n\n";
        if(ch==1)
        {
            head=delete_pos(head);
            display(head);
        }
        else
        break;
    }
    
}