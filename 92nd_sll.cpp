//delete a node recursively
//in my case the position satrts from 0
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

node *delete_at_given_pos(node *head,int pos,node *prev=nullptr)
{
    if(head==nullptr)
    {
        return prev;
    }
    else if(pos==0 && prev==nullptr)//first node
    {
        head=head->next;
        return head;
    }
    else if(pos==0)//in middle 
    {
        node *temp=head;
        prev->next=temp->next;
        delete temp;
        return prev;
    }
    else
    {
        delete_at_given_pos(head->next,pos-1,head);
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
    int pos;
    cout<<"\nEnter Position : \n";
    cin>>pos;
    cout<<"\nOld list : \n";
    recur_traversal(head);
    
    node *temp_head=delete_at_given_pos(head,pos);
    if(temp_head)
    head=temp_head;
    cout<<"\nNew list : \n";
    recur_traversal(head);
}
