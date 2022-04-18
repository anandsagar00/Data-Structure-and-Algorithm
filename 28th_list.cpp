//insert at any given position.
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
node *append(node *head)
{
    int data;
    cout<<"Enter data : ";
    cin>>data;
    //now we will create a temporary node
    node *temp=new node(data);
    if(head==nullptr)
    {
        head=temp;
    }
    else
    {
        node *p=head;
        while(p->next!=nullptr)
        p=p->next;
        p->next=temp;
    }
    return head;
}
node *insert(node *head)
{
    int num,pos;
    cout<<"Enter the number you want to insert : ";
    cin>>num;
    cout<<"\nEnter the position which you want to insert 1 or lesser to insert at front and value larger than total size to insert at last\n";
    cin>>pos;
    node *temp=new node(num);
    if(pos<=1)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        int ind=1;
        node *p=head;
        int flag=0;
        while(p->next!=nullptr)
        {
            if(ind==pos-1)
            {
                node *addr_nxt_node=p->next;//to store addrress of next node
                p->next=temp;
                temp->next=addr_nxt_node;
                flag=1;
            }
            p=p->next;
            ind++;
        }
        if(!flag)
        {
            p->next=temp;
        }
    }
    return head;
}
void display(node *head)
{
    if(head==nullptr)
    return;
    cout<<head->data<<" ";
    display(head->next);
}
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    {
        head=append(head);
    }
    while(1)
    {
        int ch;
        cout<<"\nPress 1. to insert at any index and any other key to exit.";
        cin>>ch;
        if(ch==1)
        {
            head=insert(head);
            display(head);
        }
        else
        break;
    }
}