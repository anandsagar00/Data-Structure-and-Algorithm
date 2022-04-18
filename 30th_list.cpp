//print middle of linked list using recursion
// I/P : 1 2 3 4 5  O/P : 3 
// I?P : 1 2 3 4 5 6 O/P : 4

//this code requires two traversal one to calculate total number of nodes and second to go to that particular
//(n/2)th node

//in my next code I have discussed the same using slow and fast pointer concept

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
//function to traverse the list till middle
void recur_traversal(node *head,int n)//where n is the (total node)/2
{
    static int ind=0;
    if(head==nullptr)
    {
        cout<<"Empty list";
        return;
    }
    if(ind==n)
    {
        cout<<head->data;
        return;
    }
    ind=ind+1;
    recur_traversal(head->next,n);
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
    cout<<"\nMiddle element is : ";
    recur_traversal(head,n/2);
}