//reverse a list using loops
//method 1 copy in array and copy back after reversing
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
    node *p=head;
    int arr[n];
    int cn=n;
    while(p!=nullptr)
    {
        arr[n-1]=p->data;
        n--;
        p=p->next;
    }
    p=head;
    n=0;
    while(p!=nullptr)
    {
        p->data=arr[n];
        p=p->next;
        n++;
    }
    p=head;
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

}