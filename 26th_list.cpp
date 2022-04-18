//delete front operation in a linked list
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
node *del_front(node *head)
{
    if(head!=nullptr)
    head=head->next;
    else
    cout<<"List already empty.\n";
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
        cout<<"Press 1. to delete front and any other key to exit.";
        cin>>ch;
        if(ch==1)
        {
            head=del_front(head);
            display(head);
        }
        else
        break;
    }

}