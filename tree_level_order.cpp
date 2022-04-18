#include<iostream>
#include<queue>
#include<algorithm>
#include<iterator>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int n)
    {
        data=n;
        left=nullptr;
        right=nullptr;
    }
};

node *insert_bst(node *root,int data)
{
    if(root==nullptr)
    {
        node *temp=new node(data);
        return temp;
    }
    else
    {
        if(data<root->data)
        {
            root->left=insert_bst(root->left,data);
        }
        else if(data>root->data)
        {
            root->right=insert_bst(root->right,data);
        }
        else
        {
            return root;
        }
        return root;
    }
}
void leve_order(node *root)
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp_front=q.front();
        q.pop();
        cout<<temp_front->data<<" ";
        if(temp_front->left)
        q.push(temp_front->left);
        if(temp_front->right!=nullptr)
        q.push(temp_front->right);
    }
}
int main()
{
    node *root=nullptr;
    while(1)
    {
        cout<<"Press 1 to insert\nPress 2 to display level order\nPress 3 to exit.\n";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int data;
            cout<<"Enter data : ";
            cin>>data;
            root=insert_bst(root,data);
        }
        else if(ch==2)
        {
            leve_order(root);
        }
        else 
        {
            cout<<"EXIT";
            break;
        }
    }
}