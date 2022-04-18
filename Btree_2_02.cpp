/*
Problem Statement: Construct Tree from postorder  inorder
Problem Level: MEDIUM
Problem Description:
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements.

Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
7
4 5 2 6 7 3 1 
4 2 5 1 6 3 7

Sample Output 1:
1 
2 3 
4 5 6 7

Sample Input 2:
6
2 9 3 6 10 5 
2 6 3 9 5 10

Sample Output 2:
5 
6 10 
2 3 
9
*/
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
void pre(node *root)
{
     if(root!=nullptr)
     {
         cout<<root->data<<" ";
         pre(root->left);
         pre(root->right);
    }
}
node *preorderFromInorder_Postorder(int post[],int inorder[],int n)
{
    if(n<=0)
    {
        return nullptr;
    }
    else
    {
        int root_postorder=post[n-1];
        int pos;
        node *new_root=new node(root_postorder);
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==root_postorder)
            {
                pos=i;
                break;
            }
        }
        node *left=preorderFromInorder_Postorder(post,inorder,pos);
        node *right=preorderFromInorder_Postorder(post+pos,inorder+pos+1,n-pos-1);
        new_root->left=left;
        new_root->right=right;
        return new_root;
    }
}
int main()
{
    cout<<"Enter total number of nodes in the tree : ";
    int n;
    cin>>n;
    int post[n];
    int inorder[n];
    cout<<"\nEnter post order traversal of tree : ";
    for(int i=0;i<n;i++)
    {
        cin>>post[i];
    }
    cout<<"\nEnter inorder traversal of the tree : ";
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    node *root=preorderFromInorder_Postorder(post,inorder,n);
    cout<<endl;
    pre(root);
}