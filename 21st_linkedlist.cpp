//implement linked list in C++
#include<bits/stdc++.h>
using namespace std;

//in  C++ we can have constructors for structure
// https://www.geeksforgeeks.org/difference-c-structures-c-structures/
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

/* In C we had to write 

        struct node head;
    if we wanted to create a variable of struct node type 
    BUT
    in c++ we can directly write node head
*/
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
    while(p!=nullptr)
    {
        cout<<p->data<<" --> ";
        p=p->next;
    }
}