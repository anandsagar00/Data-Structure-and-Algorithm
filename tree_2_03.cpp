/*
Problem Statement: Structurally identical
Problem Level: MEDIUM
Problem Description:
Given two generic trees, return true if they are structurally identical. Otherwise return false.
Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.

Input format :
The first line of input contains data of the nodes of the first tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line of input contains data of the nodes of the second tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output format :
The first and only line of output contains true, if the given trees are structurally identical and false, otherwise.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
true

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0

Sample Output 2:
false
*/
#include<bits/stdc++.h>
using namespace std;

//structure of a node of a tree
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
bool checkIdentical(node *root1,node *root2)
{
    if(root1==nullptr && root2==nullptr)
    return true;
    else if(root1->children.size() != root2->children.size())
    return false;
    else
    {
        bool status=true;
        for(int i=0;i<root1->children.size();i++)
        {
            if(status==false)
            return status;
            if(root1->children[i]->data!=root2->children[i]->data)
                return false;
            status=checkIdentical(root1->children[i],root2->children[i]);
        }
        return status;
    }
}
int main()
{
    cout<<"Welcome to tree creation and traversal code : \n";
    node *root1=nullptr;
    root1=takeInput(root1);
    node *root2=nullptr;
    root2=takeInput(root2);
    if(checkIdentical(root1,root2))
    cout<<"True";
    else
    cout<<"False";
}