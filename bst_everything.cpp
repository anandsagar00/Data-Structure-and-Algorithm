//insert,delete in a BST

#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data=d;
        left=nullptr;
        right=nullptr;
    }
};

node *insert(node *root,int value)
{
    if(root==nullptr)
    {
        node *temp=new node(value);
        return temp;
    }
    else
    {
        if(value<root->data)
        root->left=insert(root->left,value);
        else if(value > root->data)
        root->right=insert(root->right,value);
        else
        return root;
        return root;
    }
}
int height(node *root)
{
    if(root==nullptr)
    return 0;
    else
    {
        int left=height(root->left);
        int right=height(root->right);
        return (left>right)?left+1:right+1;
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
int inPre(node *root)
{
    node *temp=root;
    while(temp->right!=nullptr)
    temp=temp->right;
    return temp->data;
}
int inPost(node *root)
{
    node *temp=root;
    while(temp->left!=nullptr)
    temp=temp->left;
    return temp->data;
}
node *del(node *root,int data)
{
    if(root==nullptr)
    return root;
    else if(root->left==nullptr && root->right==nullptr && root->data==data)
    {
        delete root;
        return nullptr;
    }
    else
    {
        if(data<root->data)
        root->left=del(root->left,data);
        else if(data>root->data)
        root->right=del(root->right,data);
        else
        {
            int lh=height(root->left);
            int rh=height(root->right);
            if(lh>rh)
            {
                //replace the current node's data by inorder predecessor
                int inPred=inPre(root->left);
                root->data=inPred;
                root->left=del(root->left,inPred);
                return root;
            }
            else
            {
                int inPosto=inPost(root->right);
                root->data=inPosto;
                root->right=del(root->right,inPosto);
                return root;
            }
        }
        return root;
    }
}
int main()
{
    node *root=nullptr;
    while(1)
    {
        int choice;
        cout<<"\nPress 1 to insert \nPress 2 to find the height\nPress 3 to display the elements of BST.\nPress 4 to delete an element.\nPress 5 to exit.";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        if(choice==1)
        {
            int data;
            cout<<"\nEnter value to insert : ";
            cin>>data;
            root=insert(root,data);
        }
        else if(choice==2)
        {
            cout<<"\nHeight of the tree is : "<<height(root)<<endl;
        }
        else if(choice==3)
        {
            cout<<endl;
            inorder(root);
        }
        else if(choice==4)
        {
            int data;
            cout<<"Enter data to delete : ";
            cin>>data;
            root=del(root,data);
            cout<<endl<<"New tree is : \n";
            inorder(root);
        }
        else
        break;
    }
}