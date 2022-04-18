/*
Problem Statement: Next larger
Problem Level: MEDIUM
Problem Description:
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of n.

Output format :
The first and only line of output contains data of the node, whose data is just greater than n.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
18
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
20

Sample Input 2 :
21
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 2:
30
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
int nextGreater(node *root,int element)
{
    if(root==nullptr)
    return element;
    else
    {
        vector<int> nextGreaterElmentsOfChildren;
        for(int i=0;i<root->children.size();i++)
        {
            int ngeAtI=nextGreater(root->children[i],element);
            if(ngeAtI>element)
            nextGreaterElmentsOfChildren.push_back(ngeAtI);
        }
        //this variable below will store the minimum of next greater elemnts brought by the children trees
        if(nextGreaterElmentsOfChildren.size()!=0)
        {
            int nge=nextGreaterElmentsOfChildren[0];
            for(int i=0;i<nextGreaterElmentsOfChildren.size();i++)
            {
                if(nextGreaterElmentsOfChildren[i]<nge)
                nge=nextGreaterElmentsOfChildren[i];
            }
            if((root->data < nge) && (root->data > element))
            return root->data;
            else
            return nge;
        }
        if(root->data > element)
        return root->data;
    }
}
int main()
{
    cout<<"Welcome to tree creation : \n";
    node *root=nullptr;
    root=takeInput(root);
    int element;
    cout<<"Enter the element whose next greater element you want to find : ";
    cin>>element;
    int nextGreaterElement=nextGreater(root,element);
    if(element<nextGreaterElement)
    cout<<"Next greater element is : "<<nextGreaterElement;
    else
    cout<<"No Next greater element found.";
}