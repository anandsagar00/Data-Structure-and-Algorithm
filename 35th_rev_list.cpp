/*
reverse a list 
this is a very efficient method to reverse a linked list in this method we keep on reversing the links as we move forward
using 3 pointers
detailed explanation with diagram : https://www.youtube.com/watch?v=bjtMCwy_LMA&ab_channel=ApnaCollege
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
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=append(head);

    node *prev=nullptr;
    node *current=head;
    node *next;

    while(current!=nullptr)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    node *p=head;
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}