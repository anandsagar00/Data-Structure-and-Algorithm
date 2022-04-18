//In this code I have created a binary tree after taking user input
//I have also written code for iterative pre-order traversal ,iterative inorder traversal
//
#include<iostream>
using namespace std;

//structure for node of BINARY TREE
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

//creating a stack structure
struct stack
{
    node *data;
    stack *next;
    stack(node *address)
    {   
        data=address;
        next=nullptr;
    }
};
stack *push(stack *s,node *address)
{
    stack *temp=new stack(address);
    if(s==nullptr)
    s=temp;
    else
    {
        temp->next=s;
        s=temp;
    }
    return s;
}
stack *pop(stack *s)
{
    if(s!=nullptr)
    {
        stack *temp=s;
        s=s->next;
        delete temp;
    }
    else
    cout<<"Stack is Empty\n";
    return s;

}
void preorder_iterative(node *root)
{
    stack *s=nullptr;
    node *t=root;
    while(s!=nullptr || t!=nullptr)
    {
        //agar null nahi hai t to left me jao nahi to right me jaao
        if(t!=nullptr)
        {
            cout<<t->data<<" ";
            s=push(s,t);
            t=t->left;
        }
        else
        {
            t=s->data;//we just popped the address in the stack
            s=pop(s);
            t=t->right;
        }
    }
}
void inorder_iterative(node *root)
{
    stack *s=nullptr;
    node *t=root;
    while(s!=nullptr || t!=nullptr)
    {
        //agar null nahi hai t to left me jao nahi to right me jaao
        if(t!=nullptr)
        {
            s=push(s,t);
            t=t->left;
        }
        else
        {
            t=s->data;//we just popped the address in the stack
            s=pop(s);
            cout<<t->data<<" ";
            t=t->right;
        }
    }
}
//we are creating a queue DS which will store the address of type node
//implemented queue ds with the help of a linked list
//the data part of this queue is address of type node

struct queue
{
    node *data;
    queue *next;
    queue(node *address)
    {   
        data=address;
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
queue *dequeue(queue *head)//dequeues the queue
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
void levelorder(node *root)
{
    queue *q=nullptr;
    q=enque(q,root);
    cout<<root->data<<" ";
    while(!isEmpty(q))
    {
        node *t=q->data;
        q=dequeue(q);
        if(t->left!=nullptr)
        {
            cout<<t->left->data<<" ";
            q=enque(q,t->left);
        }
        if(t->right!=nullptr)
        {
            cout<<t->right->data<<" ";
            q=enque(q,t->right);
        }
    }
    
}
int main()
{
    int x;
    cout<<"Enter data in root node : ";
    cin>>x;
    node *root=new node(x);
    queue *q=nullptr;
    q=enque(q,root);
    while(!isEmpty(q))
    {
        node *temp=q->data;
        q=dequeue(q);
        int x;
        cout<<"Enter left child of "<<temp->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            node *t=new node(x);
            temp->left=t;
            q=enque(q,t);
        }
        cout<<"Enter right child of "<<temp->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            node *t=new node(x);
            temp->right=t;
            q=enque(q,t);
        }

    }
    cout<<endl;
    cout<<"Preorder traversal : \n";
    preorder(root);
    cout<<endl;
    preorder_iterative(root);
    cout<<"\nInorder Traversal : \n";
    inorder_iterative(root);
    cout<<"\nLevel Order Traversal : \n";
    levelorder(root);
}
