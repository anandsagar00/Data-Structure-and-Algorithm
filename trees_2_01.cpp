//in this code I will be creating a tree from user input
//I will also print its level order traversal
//I will also be counting number of node
//number of leaf nodes
//height of tree
//printing all nodes at a given depth d

//Sample Input is : 1 4 5 2 3 4 3 6 7 8 1 9 1 10 1 11 0 0 0 0 0 3 12 13 14 0 0 0

    //                 1
    //      /      |       \       \ 
    //     5       2       3        4
    // /   |  \    |       |         \
    // 6   7  8    9       10        11
    //                             /  |  \
    //                            12  13  14
        
//this is the tree 

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
int height(node *root)
{
    if(root==nullptr)
    return 0;
    else
    {
        vector<int> heightsofsubtree;
        for(int i=0;i<root->children.size();i++)
        {
            int heightatindexi=height(root->children[i]);
            heightsofsubtree.push_back(heightatindexi);
        }
        int max_height=0;
        for(int i=0;i<heightsofsubtree.size();i++)
        {
            if(heightsofsubtree[i]>max_height)
            max_height=heightsofsubtree[i];
        }
        return 1+max_height;
    }
}
int countleafnodes(node *root)
{
    if(root==nullptr)
    return 0;
    else if(root->children.size()==0)
    return 1;
    else
    {
        vector<int> leafNodeOfEachSubTree;
        for(int i=0;i<root->children.size();i++)
        {
            leafNodeOfEachSubTree.push_back(countleafnodes(root->children[i]));
        }
        int total=0;
        for(int i=0;i<leafNodeOfEachSubTree.size();i++)
        total+=leafNodeOfEachSubTree[i];
        return total;
    }
}
int countnodes(node *root)
{
    if(root==nullptr)
    return 0;
    else
    {
        int totalnodes=0;
        for(int i=0;i<root->children.size();i++)
        {
            totalnodes+=countnodes(root->children[i]);
        }
        return 1+totalnodes;
    }
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
void printAtDepthD(node *root,int d)
{
    if(d==0 && root!=nullptr)
    cout<<root->data<<" ";
    else if(root!=nullptr)
    {
        for(int i=0;i<root->children.size();i++)
        {
            printAtDepthD(root->children[i],d-1);
        }
    }
}
int main()
{
    cout<<"Welcome to tree creation and traversal code : \n";
    node *root=nullptr;
    root=takeInput(root);
    traverse_tree(root);
    cout<<"\n\nTotal number of nodes in the are : "<<countnodes(root);
    cout<<"\nHeight of tree is : "<<height(root);
    cout<<"\n\nTotal Leaf nodes in the tree are : "<<countleafnodes(root);
    int depth_d;
    cout<<"\nEnter the depth at which you want to print all nodes : ";
    cin>>depth_d;
    cout<<"\n\nAll Nodes at depth "<<depth_d<<" are : \n";
    printAtDepthD(root,depth_d);
}