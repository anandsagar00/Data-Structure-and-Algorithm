//Remove duplicates from a sorted Singly Linked List
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
    cout<<"Enter total nodes : ";
    cin>>n;
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=append(head);

    node *last_unique=head;//to store last unique node(first node is always unique)

    node *p=head->next;
    while(p!=nullptr)
    {
        if(p->data!=last_unique->data)
        {
            last_unique->next=p;
            last_unique=p;
        }
        if(p->data==last_unique->data && p->next==nullptr)
        {
            last_unique->next=nullptr;
        }
        p=p->next;
    }
    p=head;
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

}