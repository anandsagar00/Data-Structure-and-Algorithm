//In this code I have tried to create a Binary search tree from a given list of numbers 

#include<bits/stdc++.h>
using namespace std;

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

//this function inserts a new in the binary search tree at its given position

node *insert(node *root,int data_list[],int n)
{
    if(n>=1)
    {
        //inserting the first node in the tree
        if(root==nullptr)
        {
            root=new node(data_list[0]);
        }
        for(int i=1;i<n;i++)
        {
            int data=data_list[i];
            node *prev_node=nullptr;
            node *current_node=root;
            int flag_twice=0;//flag to denote same number inputted twice in list
            while(current_node!=nullptr)
            {
                if(data > current_node->data)
                {
                    prev_node=current_node;
                    current_node=current_node->right;
                }
                else if(data < current_node->data)
                {
                    prev_node=current_node;
                    current_node=current_node->left;
                }
                else
                {
                    flag_twice=1;
                    //coming out of the loop since the data gets repeated
                    break;
                }
            }
            //if the current data is not repeated twice then only we will insert
            if(!flag_twice)
            {
                if(data<prev_node->data)
                {
                    node *temp_node=new node(data);
                    prev_node->left=temp_node;
                }
                else
                {
                    node *temp_node=new node(data);
                    prev_node->right=temp_node;
                }
            }
        }
    }
    return root;
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
    int n;
    cout<<"Enter number of elements to insert in the BST : ";
    cin>>n;
    int data_list[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the data : ";
        cin>>data_list[i];
    }
    cout<<"\nThe Binary Search Tree (BST) created from the given list has inorder traversal as : \n";
    node *root=nullptr;
    root=insert(root,data_list,n);
    inorder(root);
}