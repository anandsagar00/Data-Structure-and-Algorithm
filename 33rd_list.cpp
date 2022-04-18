//print the nth element from the end of a linked list

/*
in this code I have chosen two pointers one is at the beginning and one is n(nlast)  positions ahead from the first ptr
as a result when the pointer (which is ahead by n positions) becomes null then the other pointer will be at nth position from
last
*/
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
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"\nEnter elements in the list : \n";
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=append(head);
    int nlast;
    cout<<"Enter the nth position : ";
    cin>>nlast;
    node *first=head;
    for(int i=1;i<=nlast;i++)//moving the first pointer n(nlast) positions ahead
    first=first->next;
    node *second=head;
    while(first!=nullptr)
    {
        first=first->next;
        second=second->next;
    }
    cout<<"\nnth element from last is : "<<second->data;
}