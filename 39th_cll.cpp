// Implement a circular linked list and print its elements
// insert front (this code does this)
// insert last (this code does this)
// insert at a specific position (this code does this)
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
node *insert(node *head)
{
    int data;
    cout<<"Enter the value you want to insert : ";
    cin>>data;
    node *temp=new node(data);
    int pos;
    cout<<"Options :\nEnter position at which you want to insert or \n";
    cout<<"1 or less to insert at front.\n";
    cout<<"number greater than size of list to insert at last.\n: ";
    cin>>pos;
    if(pos<=1)//insert front
    {
        node *old_head=head;
        node *p=head->next;//to traverse in the CLL 
        temp->next=head;
        head=temp;
        while(p->next!=old_head)
        p=p->next;
        p->next=head;
    }
    else
    {
        /*
        any other position also has two case 
        i)insert in middle 
        ii)insert at end.
        */
        node *p=head;
        int ind=2;//this is the the current position on which we are now (actually one less tha that) as the new node will be inserted
                //after this 
        int flag=0;
        while(p->next!=head)
        {
            if(pos==ind)
            {
                node *nxt_node=p->next;
                p->next=temp;
                temp->next=nxt_node;
                flag=1;
                break;
            }
            ind++;
            p=p->next;
        }
        if(flag==0)//i.e insert at last
        {
            p->next=temp;
            temp->next=head;
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
        cout<<"Press 1 to insert at any position or any key to exit : ";
        cin>>ch;
        cout<<"\n\n";
        if(ch==1)
        {
            head=insert(head);
            display(head);
        }
        else
        break;
    }
    
}