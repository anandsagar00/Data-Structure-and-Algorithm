// I will be implementing binary search tree in this code
// I will be taking user input and creating a BST with the help of a queue data structure

#include<iostream>
using namespace std;

//structure of node

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

//structure for queue 
//this queue will be storing address of nodes as its data
//creating a queue data structure using linked list

struct queue
{
    node *addr;//to store address of nodes 
    queue *next;
    queue(node *add)
    {
        addr=add;
        next=nullptr;
    }
};

//checks if the queue is empty or not
int isEmpty(queue *q)
{
    if(q==nullptr)
    return 1;
    else
    return 0;
}

//this function takes the address of the node created and stores the address in the queue
queue *enqueue(queue *q,node *addr)
{
    //we will create a temporary element/member of queue(only 1) in heap,
    /*
        In heap the element will look like
        [address of node,link to the next queue member]
    */
   queue *temp=new queue(addr);

   if(q==nullptr)
   q=temp;

   else
   {
       //linking the temp queue in heap to already existing queue

       queue *p=q;
       while(p->next!=nullptr)
       p=p->next;

       p->next=temp;
   }
   return q;
}

queue *dequeue(queue *q)
{
    if(!isEmpty(q))
    {
        q=q->next;
    }
    return q;
}
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    queue *q=nullptr;//queue to store addresses of the nodes of binary tree
    int data;
    cout<<"Enter the root's data : ";
    cin>>data;

    //creating the root node in heap and storing its address in queue

    node *root=new node(data);
    q=enqueue(q,root);
    // while(!isEmpty(q))
    // {
    //     node *p=q->addr;//to store the address of node (i.e this gives the first element of queue)
    //     q=dequeue(q);
    //     int x;
    //     cout<<"Enter data : ";
    //     cin>>x;

    //     node *temp=new node(x);//creates a temp node in heap

    //     if(x!=-1)
    //     {
    //         if(temp->data > p->data)
    //         {
    //             p->right=temp;
    //             q=enqueue(q,temp);
    //         }
    //         else
    //         {
    //             p->left=temp;
    //             q=enqueue(q,temp);
    //         }
    //     }
    
    // }
    inorder(root);
}