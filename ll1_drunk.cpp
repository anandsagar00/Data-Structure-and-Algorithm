#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=nullptr;
    }
};
node *append(node *head)
{
    int temp_input;
    cout<<"Enter the number : ";
    cin>>temp_input;
    node *temp=new node(temp_input);
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
void print_list(node *head)
{
    if(head==nullptr)
    {
        return;
    }
    else
    {
        cout<<head->data<<" -> ";
        print_list(head->next);
    }
}
int main()
{
    int n;
    cout<<"Enter number of elements in list : ";
    cin>>n;
    node *head=nullptr;
    for(int i=1;i<=n;i++)
    head=append(head);
    print_list(head);
}