//search in a linked list using recursion
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
int search(node *head,int key)
{
    if(head==nullptr)
    return 0;
    if(head->data==key)
    return 1;
    return search(head->next,key);
}
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=append(head);
    int key;
    cout<<"\nEnter key you want to search : ";
    cin>>key;
    if(search(head,key))
    {
        cout<<"Key is present in the list.";
    }
    else
    cout<<"Key is not present in the list.";
}