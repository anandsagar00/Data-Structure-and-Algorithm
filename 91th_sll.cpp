//insert a node at a given position recursively
//in my case the position starts from 0
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next=nullptr;
    }
};

node *insert_at_given_pos(node *head,int pos,int data,node *prev=nullptr)
{
    if(head==nullptr)
    {
        if(prev!=nullptr && pos==0)//if it is the last node
        {
            node *temp=new node(data);
            prev->next=temp;
            return head;
        }
        else
        return head;
        
    }
    else if(pos==0 && prev==nullptr)
    {
        node *temp=new node(data);
        temp->next=head;
        head=temp;
        return head;
    }
    else if(pos==0 && prev!=nullptr)
    {
        node *temp=new node(data);
        prev->next=temp;
        temp->next=head;
        return head;
    }
    else
    {
        insert_at_given_pos(head->next,pos-1,data,head);
        return head;
    }
}
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
void recur_traversal(node *head)
{
    if(head==nullptr)
    return;
    cout<<head->data<<" ";
    recur_traversal(head->next);
}
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    node *head=nullptr;
    while(n--)
    head=append(head);
    int pos,data;
    cout<<"\nEnter the data you want to insert : \n";
    cin>>data;
    cout<<"\nPosition : \n";
    cin>>pos;
    cout<<"\nOld list : \n";
    recur_traversal(head);
    
    node *temp_head=insert_at_given_pos(head,pos,data);
    if(temp_head)
    head=temp_head;
    cout<<"\nNew list : \n";
    recur_traversal(head);
}
