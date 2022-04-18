//merge two doubly circular linked list
/*

I/P1 : 12 13 14 15 16
I/P2 : 40 50 60 70 80

O/P : 12 40 13 50 14 60 15 70 16 80

*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data=x;
        next=nullptr;
        prev=nullptr;
    }
};

node *append(node *head)
{
    int x;
    cout<<"Enter the data : ";
    cin>>x;
    node *temp=new node(x);
    if(head==nullptr)
    {
        head=temp;
        head->next=temp;
        head->prev=temp;
    }
    else
    {
        node *p=head->prev;
        head->prev=temp;
        temp->next=head;
        temp->prev=p;
        p->next=temp;
    }
    cout<<"\n";
    return head;
}
void display(node *head)
{
    if(head==nullptr)
    {
        cout<<"List is empty.\n";
        return;
    }
    node *p=head->next;
    cout<<head->data<<" ";
    while(p!=head)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}
node *mergelists(node *nhead,node *head1,node *head2)
{
    node *p=head1->next;//point on first list

    node *q=head2->next;//point on 2nd list

    //merging the first two heads of list1 and list 2 
    //first I will join all the connections and then I will make the list circular at last
    nhead=head1;

    nhead->next=head2;

    nhead->next->prev=nhead;

    node *r=nhead->next;//pointing on new list

    while(p!=head1)
    {
        node *temp1=p->next;
        node *temp2=q->next;

        //attaching the node from first list

        r->next=p;
        p->next->prev=r;

        r=r->next;

        //attaching the node from second list

        r->next=q;
        q->prev=r;

        //making circular connection

        nhead->prev=q;
        r->next->next=nhead;
        r->next->prev=r;

        r=r->next;

        p=temp1;
        q=temp2;

    }
    return nhead;

}
int main()
{
    int n;
    cout<<"Enter number of nodes in the lists : ";
    cin>>n;

    node *head1=nullptr;
    cout<<"List 1 : \n";

    for(int i=1;i<=n;i++)
    head1=append(head1);

    cout<<"List 2 : \n";
    node *head2=nullptr;

    for(int i=1;i<=n;i++)
    head2=append(head2);

    cout<<"Original lists are : \n";
    cout<<"List 1 : ";
    display(head1);
    cout<<"List 2 : ";
    display(head2);
    cout<<"Modified list is : \n";
    node *nhead=nullptr;
    nhead=mergelists(nhead,head1,head2);
    display(nhead);
}