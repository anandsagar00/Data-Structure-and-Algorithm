//in this code I will insert/delete/do inorder traversal/max and min/search in a binary search tree
//this is the sample input i.e the tree inserted is 17 9 5 13 18 21 19 1 3 14
// 1 17 1 9 1 5 1 13 1 18 1 21 1 19 1 2 1 3 1 14
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
struct max_min
{
    int max;
    int min;
};
node *insert_node(node *root,int data)
{
    if(root==nullptr)
    {
        node *temp=new node(data);
        return temp;
    }
    else
    {
        if(root->data==data)
        {
            return root;
        }
        else if(data<root->data)
        root->left=insert_node(root->left,data);
        else if(data>root->data)
        root->right=insert_node(root->right,data);
        return root;
    }
}
int inorder_pre(node *root)//it will accept the left subtree of the current node on which we will be working
{
    node *t=root;
    while(t->right!=nullptr)
    t=t->right;
    return t->data;
}
int inorder_succ(node *root)//it will accept the right subtree of the current node on which we will be working
{
    node *t=root;
    while(t->left!=nullptr)
    t=t->left;
    return t->data;
}
int height(node *root)//returns the height of the tree
{
    if(root==nullptr)
    return 0;
    else
    {
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
}
node *delete_node(node *root,int data)
{
    if(root==nullptr)
    return root;
    if(root->left==nullptr && root->right==nullptr && root->data==data)
    {
        //handling the case when the node to be deleted is leaf node
        return nullptr;
    }
    else
    {
        if(data<root->data)
        root->left=delete_node(root->left,data);
        else if(data>root->data)
        root->right=delete_node(root->right,data);
        else
        {
            if(height(root->left)>height(root->right))
            {
                //when left subtree's height is greater then the right then we will
                //replace current node's data from inorder predecessor
                int pred=inorder_pre(root->left);
                root->data=pred;
                delete_node(root->left,pred);
            }
            else
            {
                //when right subtree's height is greater then the left then we will
                //replace current node's data from inorder successor
                int succ=inorder_succ(root->right);
                root->data=succ;
                delete_node(root->right,root->data);
            }
        }
        return root;
    }
}
bool search(node *root,int key)
{
    if(root==nullptr)
    return false;
    else
    {
        bool search_result;
        if(key<root->data)
        search_result=search(root->left,key);
        else if(key>root->data)
        search_result=search(root->right,key);
        else
        return true;
        return search_result;
    }
}
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
max_min maximum_minimum(node *root)
{
    if(root==nullptr)
    {
        max_min mm;
        mm.min=INT_MAX;
        mm.max=INT_MIN;
        return mm;
    }
    else
    {
        max_min leftT=maximum_minimum(root->left);
        max_min rightT=maximum_minimum(root->right);
        max_min final;
        //assigning the max value in the final structure
        if(leftT.max > rightT.max && leftT.max>root->data)
        {
            final.max=leftT.max;
        }
        else if(rightT.max > leftT.max && rightT.max>root->data)
        {
            final.max=rightT.max;
        }
        else
        final.max=root->data;
        //assigning the least value in the structure
        if(leftT.min <rightT.min && leftT.min<root->data)
        {
            final.min=leftT.min;
        }
        else if(rightT.min < leftT.min && rightT.min < root->data)
        {
            final.min=rightT.min;
        }
        else
        final.min=root->data;

        return final;
    }
}
int main()
{
    node *root=nullptr;
    while(1)
    {
        cout<<"\nPress 1 to insert element in the bst ."<<endl;
        cout<<"Press 2 to search an element in the bst ."<<endl;
        cout<<"Press 3 to delete an element in the bst ."<<endl;
        cout<<"Press 4 to find the maximum and minimum element in the bst ."<<endl;
        cout<<"Press 5 for inorder traversal of the bst."<<endl;
        cout<<"Press any other key to exit program."<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int data;
            cout<<"Enter data to insert in the BST : ";
            cin>>data;
            root=insert_node(root,data);
            cout<<endl;
        }
        else if(choice==2)
        {
            int key;
            cout<<"Enter key to search in the bst : ";
            cin>>key;
            if(search(root,key))
            {
                cout<<key<<" is present in the tree.\n";
            }
            else 
            cout<<"KEY is not present in the tree.\n";
        }
        else if(choice==3)
        {
            int data;
            cout<<"Enter the element you want to delete from the tree : ";
            cin>>data;
            root=delete_node(root,data);
            cout<<endl;
        }
        else if(choice==4)
        {
            max_min mm=maximum_minimum(root);
            cout<<"The maximum element in the bst is : "<<mm.max<<endl;
            cout<<"The minimum element in the bst is : "<<mm.min<<endl;
        }
        else if(choice==5)
        {
            inorder(root);
        }
        else 
        {
            cout<<"_____________T           A               T               A__________________________";
            break;
        }
    }
}