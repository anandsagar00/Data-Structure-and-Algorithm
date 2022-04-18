//in this code I have created a tree using level order and also I have written code for iterative preorder traversal

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

void iterative_preorder(node *root)
{
    stack<node *> s;
    node *temp_ptr=root;
    while(!s.empty() || temp_ptr!=nullptr)
    {
        if(temp_ptr!=nullptr)
        {
            cout<<temp_ptr->data<<" ";
            s.push(temp_ptr);
            temp_ptr=temp_ptr->left;
        }
        else
        {
                temp_ptr=s.top();
                s.pop();
                temp_ptr=temp_ptr->right;
        }
    }
}

int main()
{
    //I will be using STl's stack and queue
    node *root=nullptr;
    int x;
    cout<<"Enter the data in root of the tree : ";
    cin>>x;
    root=new node(x);
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *front_of_q=q.front();
        q.pop();
        int data_in_node;
        cout<<"Enter data in the left child of "<<front_of_q->data<<" : ";
        cin>>data_in_node;
        //if the data inputted is +ve then we will create and link the data in the left node of the current node
        if(data_in_node!=-1)
        {
            //since data is not -1 we will link a new node to the left of current node and we will push the address of temp_node in quueue
            node *temp_node=new node(data_in_node);
            front_of_q->left=temp_node;//linking
            q.push(temp_node);
        }
        cout<<"Enter data in the right child of "<<front_of_q->data<<" : ";
        cin>>data_in_node;
        //if the data inputted is not -1 then we will create and link the data in the left node of the current node
        if(data_in_node>=0)
        {
            //since data is +ve we will link a new node to the right of current node and we will push the address of temp_node in quueue
            node *temp_node=new node(data_in_node);
            front_of_q->right=temp_node;
            q.push(temp_node);
        }

    }
    iterative_preorder(root);
}