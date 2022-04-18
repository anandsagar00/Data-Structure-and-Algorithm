/*
in this code I have tried to create a Binary search tree
                                                        or
I have tried to insert node in the Binary search tree using iteration
*/

//deleting a node using succesor and predecessor method

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
    node *temp=root;
    node *prev_node=nullptr;
    while(temp!=nullptr)
    {
        if(data<temp->data)
        {
            prev_node=temp;
            temp=temp->left;
        }
        else if(data>temp->data)
        {
            prev_node=temp;
            temp=temp->right;
        }
        else
        {
            return root;
        }
    }
    if(data>prev_node->data)
    {
        node *new_node=new node(data);
        prev_node->right=new_node;
    }
    else
    {
        node *new_node=new node(data);
        prev_node->left=new_node;
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
node *inorder_predecessor(node *root)
{
    //this function returns the inorder predecessor of a given node in a BST
    node *temp=nullptr;
    while(root!=nullptr)
    {
        temp=root;
        root=root->right;
    }
    return temp;
}
node *inorder_succesor(node *root)
{
    //this function returns the inorder succesor of a given node in a BST
    node *temp=nullptr;
    while(root!=nullptr)
    {
        temp=root;
        root=root->right;
    }
    return temp;
}
int height_of_tree(node *root)
{
    if(root==nullptr)
    return 0;
    else
    {
        //we will calculate the height of left subtree and then that of right subtree
        int left_subtree_height=height_of_tree(root->left);
        int right_subtree_height=height_of_tree(root->right);
        if(left_subtree_height > right_subtree_height)
        return 1+left_subtree_height;
        else
        return 1+right_subtree_height;
    }
}
node *delete_bst(node *root,int data)
{
    if(root==nullptr)
    return nullptr;
    else if(root->data==data && root->left==nullptr && root->right==nullptr)
    {
        //if the node to be deleted is a leaf node then we can directly delete without any tension of any succesor/predecesor
        
        node *temp=root;
        root=nullptr;
        delete temp;
        return root;
    }
    else
    {
        if(data > root->data)
        {
            root->right= delete_bst(root->right,data);
            return root;
        }
        else if(data < root->data)
        {
            root->left=delete_bst(root->left,data);
            return root;
        }
        else
        {
            //if the left subtree is higher than the right subtree of current node then
            //we will replace the current node with it's inorder predecessor
            if(height_of_tree(root->left) > height_of_tree(root->right))
            {
                node *inorder_pred=inorder_predecessor(root->left);
                root->data=inorder_pred->data;
                root->left=delete_bst(inorder_pred,inorder_pred->data);
                return root;
            }
            //otherwise we will replace the node to be deleted with its inorder succesor
            else
            {
                node *inorder_succ=inorder_succesor(root->right);
                root->data=inorder_succ->data;
                root->right=delete_bst(inorder_succ,inorder_succ->data);
                return root;
            }
            //return root;
        }
    }
}
int main()
{
    int data;
    node *root=nullptr;
    while(1)
    {
        cout<<"Press 1 to insert a node in BST ."<<endl;
        cout<<"Press 2 to print inorder traversal of BST ."<<endl;
        cout<<"Press 3 to delete a node from BST ."<<endl;
        cout<<"Press 4 to find the height of the tree ."<<endl;
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
            if(root==nullptr)
            cout<<"Empty tree .\n";
            inorder(root);
        }
        else if(choice==3)
        {
            cout<<"\nEnter the data which you want to delete from BST : ";
            cin>>data;
            root=delete_bst(root,data);
        }
        else if(choice==4)
        {
            cout<<"\nHeight of the binary tree is : "<<height_of_tree(root)<<endl;
        }
        else
        {
            cout<<"\nExited from the program.\n";
            break;
        }

    }
}