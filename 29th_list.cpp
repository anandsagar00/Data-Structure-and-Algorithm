//The linked list should remain sorted after insertion.

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

node *append_sorted(node *head)
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    node *temp=new node(n);
    if(head==nullptr)//in case of first node
    head=temp;
    else
    {
        if(temp->data<head->data)//if the new node's data < the first node's data then insert front
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            node *p=head;//current node
            node *prev=nullptr;//previous node
            int flag=0;
            while(p!=nullptr)
            {
                if(p->data > temp->data)
                {
                    temp->next=p;
                    prev->next=temp;
                    flag=1;
                    break;
                }
                prev=p;
                p=p->next;
            }
            if(flag==0)//if the new node's data is greater than all the data in the list in simple words if new node
            {                                                                                 //isn't inserted anywhere          
                prev->next=temp;
            }
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
    cout<<"\nEnter elements in the list : \n";
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=append_sorted(head);
    display(head);
}