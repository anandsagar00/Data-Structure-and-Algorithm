//in this code I have tried to create BST from the user inputs given
//and after that I did inorder traversal of tree
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        left=0;
        right=0;
        data=x;
    }
};

node *create(node *root,int data)
{
    node *r=0;
    node *t=root;
    while(t!=0)
    {
        r=t;
        if(data==t->data)
        return root;
        else if(data<t->data)
        t=t->left;
        else if(data>t->data)
        t=t->right;
    }
    node *temp=new node(data);
    if(data<r->data)
    r->left=temp;
    else
    r->right=temp;
    return root;
}

void inorder_traversal(node *root)
{
    if(root)
    {
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);

    }
}
int main()
{
    int x;
    cout<<"Enter data : ";
    cin>>x;
    node *root=new node(x);
    while(1)
    {
        cout<<"Enter data or -256 to exit : ";
        cin>>x;
        if(x!=-256)
        root=create(root,x);
        else
        break;
    }
    cout<<endl;
    inorder_traversal(root);
}