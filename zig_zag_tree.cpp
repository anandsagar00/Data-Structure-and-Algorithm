/*
Problem Statement: ZigZag tree
Problem Level: HARD
Problem Description:
Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :
5
10 6
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

node *create_tree(node *root)
{
    cout<<"Enter the data in the root node : ";
    int x;
    cin>>x;
    root=new node(x);
    node *temp=root;
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *t=q.front();
        q.pop();
        cout<<"Enter left child of "<<t->data<< " : ";
        cin>>x;
        if(x>=0)
        {
            node *left_child=new node(x);
            t->left=left_child;
            q.push(left_child);
        }
        cout<<"Enter right child of "<<t->data<< " : ";
        cin>>x;
        if(x>=0)
        {
            node *right_child=new node(x);
            t->right=right_child;
            q.push(right_child);
        }

    }
    return root;
}
void zig_zag(node *root)
{
    //complete it 
}
int main()
{
    node *root=nullptr;
    root=create_tree(root);
    zig_zag(root);
}