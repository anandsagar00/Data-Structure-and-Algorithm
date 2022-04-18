//incomplete
/*
Problem Statement: Replace with depth
Problem Level: MEDIUM
Problem Description:
You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output format:
The updated tree is printed level wise. Each level is printed in a new line. Please refer to sample output 1 for more details.

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1:
0 
1 1 1 
2 2
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    vector <node *> children;//this vector will store the address of the children of the current node
    node(int x)
    {
        data=x;
    }
};
//in this function I will be taking user input in a tree level wise
node *takeInput(node *root)
{
    cout<<"Enter data in the root node : ";
    int data;
    cin>>data;
    root=new node(data);
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        cout<<"Enter number of children of "<<temp->data<<" : ";
        int children;
        cin>>children;
        for(int i=0;i<children;i++)
        {
            cout<<"Enter child of "<<temp->data<<" node : ";
            cin>>data;
            node *temp2=new node(data);
            temp->children.push_back(temp2);
            q.push(temp2);
        }
    }
    return root;
}
void replaceWithDepth(node *root)
{
   //function to complete
}
void traverse_tree(node *root)
{
    if(root!=nullptr)
    {
        queue<node *> q;
        cout<<root->data<<" ";
        q.push(root);
        while(!q.empty())
        {
            node *temp=q.front();
            q.pop();
            for(int i=0;i<temp->children.size();i++)
            {
                cout<<temp->children[i]->data<<" ";
                q.push(temp->children[i]);
            }
        }
    }
    else
    cout<<"Empty tree.";
}
int main()
{
    cout<<"Welcome to tree creation : \n";
    node *root=nullptr;
    root=takeInput(root);
    int element;
    replaceWithDepth(root);
    traverse_tree(root);
}