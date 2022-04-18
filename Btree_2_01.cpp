//create or print the postorder traversal when inorder and preorder traversals are given.

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
int s=0;
node *post_from_in_and_pre(int preorder[],int inorder[],int n)
{
    if(n<=0)
    {
        node *temp=nullptr;
        return temp;
    }
    else
    {
        int root_preorder=preorder[0];
        int pos;
        node *root=new node(root_preorder);
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==root_preorder)
            {
                pos=i;
                break;
            }
        }
        node *left_subtree=post_from_in_and_pre(preorder+1,inorder,pos);
        node *right_subtree=post_from_in_and_pre(preorder+1+pos,inorder+pos+1,n-pos-1);
        root->left=left_subtree;
        root->right=right_subtree;
        return root;
    }
}
void post(node *root)
{
     if(root!=nullptr)
     {
         post(root->left);
         post(root->right);
         cout<<root->data<<" ";
     }
}
int main()
{
    int n;
    cout<<"Enter the total number of nodes in the tree : ";
    cin>>n;
    int *pre=new int[n];
    int *inorder=new int[n];
    cout<<"Enter elements of preorder : ";
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    cout<<"\nEnter elements in INORDER : ";
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    cout<<"\nPreorder is : ";
    for(int i=0;i<n;i++)
    cout<<pre[i]<<" ";
    cout<<"\nInOrder is : ";
    for(int i=0;i<n;i++)
    cout<<inorder[i]<<" ";
    cout<<"\nPostOrder is : ";
    node *root=post_from_in_and_pre(pre,inorder,n);
    cout<<endl;
    post(root);
}