/*
Problem Statement: Level order traversal
Problem Level: EASY
Problem Description:
For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.
Example:

For the above-depicted tree, when printed in a level order fashion, the output would look like:

10
20 30 
40 50 60
Where each new line denotes the level in the tree.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1

Sample Output 1:
10 
20 30 
40 50 60

Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
8 
3 10 
1 6 14 
4 7 13

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
void level_order(node *root)
{
    cout<<"\n"<<endl;
   node *temp=root;
   queue<node *> q;
   if(root!=nullptr)
   {
       q.push(root);
       q.push(nullptr);
   }
   else
   {
       cout<<"The tree has not been created yet.";
       return;
   }
   while(!q.empty())
   {
       node *front_of_q=q.front();
       q.pop();
       if(front_of_q==nullptr && q.empty())
       {
           cout<<"\n";
           break;
       }
       else if(front_of_q==nullptr && !q.empty())
       {
           cout<<endl;
           q.push(nullptr);
       }
       else
       {
           cout<<front_of_q->data<<" ";
           if(front_of_q->left!=nullptr)
           q.push(front_of_q->left);
           if(front_of_q->right!=nullptr)
           q.push(front_of_q->right);
       }
   }

}
int main()
{
    node *root=nullptr;
    root=create_tree(root);
    level_order(root);
}