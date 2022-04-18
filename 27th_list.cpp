//delete last operation in a linked list
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
node *del_last(node *head)
{
    if(head==nullptr)
    {
        cout<<"List already empty.";
    }
    else if(head->next==nullptr)
    {
        head=nullptr;
    }
    else
    {
        node *p=head;
        while(p->next->next!=nullptr)
        p=p->next;
        node *temp=p->next->next;
        p->next=nullptr;
        delete temp;
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
        cout<<"\nPress 1. to delete last and any other key to exit.";
        cin>>ch;
        if(ch==1)
        {
            head=del_last(head);
            display(head);
        }
        else
        break;
    }

}