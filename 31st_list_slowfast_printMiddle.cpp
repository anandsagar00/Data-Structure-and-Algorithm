//print middle of linked list using recursion
// I/P : 1 2 3 4 5  O/P : 3 
// I?P : 1 2 3 4 5 6 O/P : 4

//using slow and fast pointer where slow moves by one and fast moves by two

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
    cout<<"Enter elements in the list : \n";
    for(int i=1;i<=n;i++)
    {
        head=append(head);
    }
    node *fast=head;
    node *slow=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"The middle element is : "<<slow->data;
}