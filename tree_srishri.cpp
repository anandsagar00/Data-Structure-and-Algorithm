//create a tree using level oredr input and produce its level order traversal

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

int main()
{
    cout<<"Enter data in the root node : ";
    int data;
    cin>>data;
    node *root=new node(data);
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        cout<<"Enter left child of "<<temp->data<<" : ";
        cin>>data;
        if(data>=0)
        {
            node *left_child=new node(data);
            temp->left=left_child;
            q.push(left_child);
        }
        cout<<"\n\nEnter right child of "<<temp->data<<" : ";
        cin>>data;
        if(data>=0)
        {
            node *right_child=new node(data);
            temp->right=right_child;
            q.push(right_child);
        }
    }
    cout<<"\n\nYou have succesfully given input to the tree.\n\nLevel Order Traversal is : \n\n";
    queue<node *> traverse;
    cout<<root->data<<" ";
    q.push(root);
    while(!q.empty())
    {
        node *front_of_q=q.front();
        q.pop();
        if(front_of_q->left!=nullptr)
        {
            cout<<front_of_q->left->data<<" ";
            q.push(front_of_q->left);
        }
        if(front_of_q->right!=nullptr)
        {
            cout<<front_of_q->right->data<<" ";
            q.push(front_of_q->right);
        }
    }
}