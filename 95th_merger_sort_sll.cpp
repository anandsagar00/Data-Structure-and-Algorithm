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
node *middle_of_list(node *head)
{
    if(head->next==nullptr)
    return head;
    node *slow=head;
    node *fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node *merge_sorted_lists(node *head1,node *head2)
{
//     node *p=h1;
//     node *q=h2;
//     node *final_list=nullptr;
//     node *r=nullptr;
//     while(p!=nullptr && q!=nullptr)
//     {
//         if(p->data<=q->data && final_list==nullptr)
//         {
//             final_list=p;
//             r=final_list;
//             p=p->next;
//         }
//         else if(p->data > q->data && final_list==nullptr)
//         {
//             final_list=q;
//             r=final_list;
//             q=q->next;
//         }
//         else if(p->data <= q->data)
//         {
//             r->next=p;
//             r=r->next;
//             p=p->next;
//         }
//         else if(p->data>q->data)
//         {
//             r->next=q;
//             r=r->next;
//             q=q->next;
//         }
//     }
//     if(p!=nullptr)
//     r->next=p;
//     else
//     r->next=q;
//     return final_list;
    node *final=nullptr;
    node *p=head1;
    node *q=head2;
    node *r=nullptr;
    while(p!=nullptr && q!=nullptr)
    {
        if((p->data<=q->data )&& final==nullptr)
        {
            final=p;
            p=p->next;
            r=final;
        }
        else if((p->data>q->data )&& final==nullptr)
        {
            final=q;
            q=q->next;
            r=final;
            
        }
        else if(p->data<=q->data)
        {
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else
        {
            r->next=q;
            q=q->next;
            r=r->next;
        }
    }
    if(p==nullptr)
    {
        r->next=q;
    }
    else
    r->next=p;
    return final;
}

node *mergersort_list(node *head)//there is an error in this code
{
    // if(head->next==nullptr || head==nullptr)
    // {
    //     return head;
    // }
    // else
    // {
    //     node *middle_element=middle_of_list(head);  
    //     node *h2;
    //     node *h1;
    //     h2=middle_element->next;
    //     node *temp=head;
    //     while(temp!=middle_element)
    //     temp=temp->next;
    //     temp->next=nullptr;
    //     h1=head;
    //     h1= mergersort_list(h1);
    //     h2= mergersort_list(h2);
    //     node *sorted_list=merge_sorted_lists(h1,h2);
    //     return sorted_list;
    // }
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
    head=mergersort_list(head);
    recur_traversal(head);
}