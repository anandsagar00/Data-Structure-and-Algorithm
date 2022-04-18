/*
in this code I have tried to create a Binary search tree
                                                        or
I have tried to insert node in the Binary search tree recursively
*/
#include<bits/stdc++.h>
using namespace std;
//creating structure for node

struct node
{
    int data;
    node *left;
    node *right;
    node(int data_in)
    {
        data=data_in;
        left=nullptr;
        right=nullptr;
    }
};

node *insert_node(node *root,int data)
{
    if(root==nullptr)
    {
        node *node_to_insert=new node(data);
        return node_to_insert;
    }
    else
    {
        if(data > root->data)
        {
            root->right=insert_node(root->right,data);
            return root;
        }
        else if(data < root->data)
        {
            root->left=insert_node(root->left,data);
            return root;
        }
        else
        {
            return root;
        }
    }
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
    int data;
    node *root=nullptr;
    while(1)
    {
        cout<<"\nPress 1 to insert a node in BST ."<<endl;
        cout<<"Press 2 to print inorder traversal of BST ."<<endl;
        cout<<"Press any other keys to exit."<<endl;
        cout<<"Enter your choice : ";
        int choice;
        cin>>choice;
        if(choice==1)
        {
            cout<<"\nEnter data to be inserted : ";
            cin>>data;
            if(root==nullptr)
            root=new node(data);
            else
            root=insert_node(root,data);
        }
        else if(choice==2)
        {
            cout<<"\n";
            inorder(root);
        }
        else
        {
            cout<<"\nExited from the program.\n";
            break;
        }

    }
}