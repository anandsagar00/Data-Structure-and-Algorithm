//remove duplicates from a sorted linked list

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
node *remove_duplicates(node *head)
{
    node *p=head;
    node *q=nullptr;
    while(p!=nullptr && p->next!=nullptr)
    {
        if(p->data==p->next->data)
        {
            node *temp=p->next;
            p->next=temp->next;
            delete temp;
        }
        else
        {
            p=p->next;
        }
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
    cout<<"\nOld list : \n";
    recur_traversal(head);
    head=remove_duplicates(head);
    cout<<"\nNew list : \n";
    recur_traversal(head);
}