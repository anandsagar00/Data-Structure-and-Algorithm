/*
Problem Description:
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

Sample Output 1 :
1
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
int sum_of_children(node *root)
{
    //this function return the sum of all the children nodes
    if(root==nullptr || root->children.size()==0)
    return 0;
    else
    {
        int sum=0;
        for(int i=0;i<root->children.size();i++)
        sum+=root->children[i]->data;
        return sum;
    }
}
int node_with_max_sum(node *root)
{
    //this function calculates the node which has maximum children's sum
    if(root==nullptr || root->children.size()==0)
    return 0;
    else
    {
        //this stores the sum of all children node of current node(below)
        int current_node_sum=sum_of_children(root);
        //this is going to store the maximum of all the sum of all the grand-children nodes(below)
        int children_node_sum_max=INT_MIN;
        int node_value;
        for(int i=0;i<root->children.size();i++)
        {
            int sumofchildren=sum_of_children(root->children[i]);
            if(sumofchildren>children_node_sum_max)
            {
                children_node_sum_max=sumofchildren;
                node_value=root->children[i]->data;
            }
        }
        if(current_node_sum>children_node_sum_max)
        return root->data;
        else
        return node_value;
    }
}
int main()
{
    cout<<"Welcome to tree creation and traversal code : \n";
    node *root=nullptr;
    root=takeInput(root);
    cout<<"\n\nNode with maximum children node sum is : "<<node_with_max_sum(root);
}
