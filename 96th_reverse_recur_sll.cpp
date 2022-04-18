//reerse a linked list recursively
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int d)
    {
        data=d;
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
node *reverse_list(node *head)
{
    if(head->next==nullptr ||  head==nullptr)
    return head;
    else
    {
        node *small_reverse=reverse_list(head->next);
        node *p=small_reverse;
        //1st approach
        node *tail=head->next;
        head->next=nullptr;
        tail->next=head;
        //2nd approach
        // while(p->next!=nullptr)
        // p=p->next;
        // head->next=nullptr;
        // p->next=head;
        return small_reverse;
    }
}

void recur_traversal(node *head)
{
    if(head==nullptr)
    return;
    cout<<head->data<<" ";
    recur_traversal(head->next);
}
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    node *head=nullptr;
    while(n--)
    {
        head=append(head);
    }
    cout<<"\nOLD LIST : \n";
    recur_traversal(head);
    cout<<"\nNEW LIST : \n";
    head=reverse_list(head);
    recur_traversal(head);
}