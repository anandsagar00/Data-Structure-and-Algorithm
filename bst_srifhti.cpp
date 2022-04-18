//create a Binary Search Tree and do inorder traversal and also search a key.
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
void insert_node(node *root,int data)
{
    node *temp=root;
    node *prev=nullptr;
    while(temp)
    {
        int d=temp->data;
        if(data<d)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(data>d)
        {
            prev=temp;
            temp=temp->right;
        }
        else 
        {
            return;
        }
    }
    if(data<prev->data)
    {
        node *left_bst=new node(data);
        prev->left=left_bst;
    }
    else
    {
        node *right_bst=new node(data);
        prev->right=right_bst;
    }
}
void inorder(node *root)
{
    if(root!=nullptr)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
bool search_bst(node *root,int key)
{
    if(root==nullptr)
    {
        return false;
    }
    else
    {
        int d=root->data;
        bool search_result;
        if(key<d)
        {
            search_result=search_bst(root->left,key);
        }
        else if(key>d)
        {
            search_result=search_bst(root->right,key);
        }
        else 
        return true;
        return search_result;
    }
}
int main()
{
    int data;
    cout<<"Enter data in root node : ";
    cin>>data;
    node *root=new node(data);
    while(1)
    {
        int choice;
        cout<<"Press 1 to insert a data in BST."<<endl;
        cout<<"Press 2 to do inorder traversal."<<endl;
        cout<<"Press 3 for searching a key."<<endl;
        cout<<"Any other key to exit."<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the value to insert : ";
            cin>>data;
            insert_node(root,data);
            cout<<endl;
        }
        else if(choice==2)
        {
            inorder(root);
            cout<<endl;
        }
        else if(choice==3)
        {
            cout<<"Enter the key to search : ";
            cin>>data;
            bool search_result=search_bst(root,data);
            if(search_result)
            {
                cout<<"Yes the key is present in BST."<<endl;
            }
            else
            cout<<"No the key is not present in the BST."<<endl;
        }
        else
        {
            break;
        }
    }
}