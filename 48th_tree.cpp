//this is an incomplete code

//create a tree (take input from user to create a tree)
#include<iostream>
using namespace std;

//this is the structure of binary tree
struct node
{
    node *left;
    int data;
    node *right;
    node(int x)
    {
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

//the queue below stores the addresses of the nodes of tree
struct queue
{
    node *addr;
    queue *next;
    queue(node *a)
    {
        addr=a;
        next=nullptr;
    }
};

queue *enque(queue *head,node *addr)//to enqueue in a queue
{
    queue *temp=new queue(addr);
    if(head==nullptr)
    head=temp;
    else
    {
        queue *p=head;
        while(p->next!=nullptr)
        p=p->next;
        p->next=temp;

    }
    return head;
}
int isEmpty(queue *head)//checks for empty queue
{
    if(head==nullptr)
    return 1;
    else
    return 0;
}
queue *dequeue(queue *head)
{
    if(!isEmpty(head))
    {
        head=head->next;
    }
    return head;
}
void preorder(node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    queue *q=nullptr;
    int data;
    cout<<"Enter ROOT data : ";
    cin>>data;
    node *root=new node(data);
    q=enque(q,root);
    while(!isEmpty(q))
    {
        node *p=q->addr;//address of node or data which is there in queue (as this queue holds addresses of node as its data)
        q=dequeue(q);
        int x;
        cout<<"Enter left child of "<<p->data<<"  :  ";
        cin>>x;
        if(x!=-1)
        {
            node *temp=new node(x);
            p->left=temp;
            q=enque(q,temp);
        }
        cout<<"Enter right child of "<<p->data<<"  :  ";
        cin>>x;
        if(x!=-1)
        {
            node *temp=new node(x);
            p->right=temp;
            q=enque(q,temp);
        }
    }
    preorder(root);

}
