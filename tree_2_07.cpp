/*
Problem Statement: Second Largest Element In Tree
Problem Level: MEDIUM
Problem Description:
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
40
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
int largest(node *root)
{
    if(root->children.size()==0)
    return root->data;
    else
    {
        vector <int> largest_array;
        for(int i=0;i<root->children.size();i++)
        {
            largest_array.push_back(largest(root->children[i]));
        }
        if(largest_array.size()>0)
        {
            int lar=largest_array[0];
            for(int i=0;i<largest_array.size();i++)
            {
                if(largest_array[i]>lar)
                lar=largest_array[i];
            }
            if(root->data>lar)
            return root->data;
            else
            return lar;
        }
        else
        {
            return root->data;
        }

    }
}
int largestelement;
int secondlargest(node *root)
{
    
}
int main()
{
    cout<<"Welcome to tree creation : \n";
    node *root=nullptr;
    root=takeInput(root);
    largestelement=largest(root);
    cout<<"\n\nSecond largest element in the tree is : "<<secondlargest(root);
}