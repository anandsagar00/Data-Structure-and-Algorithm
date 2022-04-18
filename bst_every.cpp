#include<iostream>
#include<limits.h>
#include<string>
#include<vector>
using namespace std;
//creating the structure of node
struct node 
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};
//creating and returning the pointer to the node
node *createNode(int a)
{
    node *temp=new node(a);
    return temp;
}
//insert

node *insert_bst(node *root,int data)
{
    if(root==nullptr)
    {
        node *temp=createNode(data);
        return temp;
    }
    else
    {
        if(data<root->data)
        root->left=insert_bst(root->left,data);
        else if(data>root->data)
        root->right=insert_bst(root->right,data);
        else
        {
            //as same value can't co-exist in a bst
            return root;
        }
        return root;
    }
}
int height(node *root)
{
    if(root==nullptr)
    return 0;
    else
    {
        int lh=height(root->left);
        int rh=height(root->right);
        return lh>rh?lh+1:rh+1;
    }
}
int max_in_left_subtree(node *root)
{
    node *temp=root;
    while(temp->right!=nullptr)
    temp=temp->right;
    return temp->data;
}
int min_in_right_subtree(node *root)
{
    node *temp=root;
    while(temp->left!=nullptr)
    temp=temp->left;
    return temp->data;
}
bool search(node *root,int key)
{
    if(root==nullptr)
    return false;
    else
    {
        bool state;
        if(key<root->data)
        state=search(root->left,key);
        else if(key>root->data)
        state=search(root->right,key);
        else
        {
            return true;
        }
        return state;
    }
}
int max_tree_method2(node *root)
{
    if(root->right==nullptr)
    return root->data;
    else 
    {
        node *temp=root;
        while(temp->right!=nullptr)
        temp=temp->right;
        return temp->data;
    }
}
int max_tree(node *root)
{
    if(root==nullptr)
    return INT_MIN;
    else
    {
        int lar_left=max_tree(root->left);
        int lar_right=max_tree(root->right);
        if(root->data>lar_left && root->data>lar_right)
        return root->data;
        else if(lar_left>root->data && lar_left>lar_right)
        return lar_left;
        else
        return lar_right;
    }
}
int min_tree(node *root)
{
    if(root==nullptr)
    return INT_MAX;
    else
    {
        int min_left=min_tree(root->left);
        int min_right=min_tree(root->right);
        int root_data=root->data;
        if(root_data<min_left && root_data<min_right)
        return root_data;
        else if(min_left<root_data && min_left<min_right)
        return min_left;
        else
        return min_right;
    }
}
int count_nodes(node *root)
{
    if(root==nullptr)
    return 0;
    else
    {
        int left=count_nodes(root->left);
        int right=count_nodes(root->right);
        return left+right+1;
    }
}
void inorder_sec_lar(node *root,int arr[],int n,int index)
{
    if(n==0)
    return;
    else if(root==nullptr)
    return;
    else
    {
        inorder_sec_lar(root->left,arr,n,index);
        arr[index]=root->data;
        inorder_sec_lar(root->right,arr,n-1,index);
    }
}

void find_parent(node *root,int data,int parent)
{
    if(root==nullptr)
    return;
    else if(root->data==data)
    {
        if(parent==-1)
        cout<<"Parent doesn't exist.\n";
        else
        cout<<"Parent is "<<parent<<" .\n"<<endl;
    }
    else
    {
        find_parent(root->left,data,root->data);
        find_parent(root->right,data,root->data);
    }
}
void inorder_sec_lar(node *root,vector<int> &v)
{
    if(root)
    {
        inorder_sec_lar(root->left,v);
        v.push_back(root->data);
        inorder_sec_lar(root->right,v);
    }
}
void print_sec_lar(node *root)
{
    vector<int> v;
    inorder_sec_lar(root,v);
    int s=v.size();
    cout<<v[s-2]<<endl;
}
//1 100 1 357 1 237 1 152 1 389 1 367 1 38 1 39 1 -367 1 37
node *delete_bst(node *root,int data)
{
    if(root==nullptr)
    return nullptr;
    else if(root->left==nullptr && root->right==nullptr)
    {
        delete root;
        return nullptr;
    }
    else
    {
        if(data<root->data)
        {
            root->left=delete_bst(root->left,data);
        }
        else if(data>root->data)
        {
            root->right=delete_bst(root->right,data);
        }
        else
        {
            int lh=height(root->left);
            int rh=height(root->right);
            if(lh>rh)
            {
                root->data=max_in_left_subtree(root->left);
                root->left=delete_bst(root->left,root->data);
            }
            else
            {
                root->data=min_in_right_subtree(root->right);
                root->right=delete_bst(root->right,root->data);
            }
            return root;
        }
        return root;
    }
}
void print_second_largest(node *root,int n)
{
    if(root==nullptr)
    return;
    else
    {
        print_second_largest(root->right,n);
        if(n==2)
        {
            cout<<root->data<<" ";
            return;
        }
        print_second_largest(root->left,n+1);
    }
}
void sec_lar_method2(node *root,int *c)
{
    if(root==nullptr || *c>=2)
    {
        return;
    }
    else
    {
        sec_lar_method2(root->right,c);
        (*c)++;
        if(*c==2)
        {
            cout<<"Second largest element is "<<root->data<<endl;
        }
        sec_lar_method2(root->left,c);
    }
}
void print_leaves(node *root)
{
    if(root==nullptr)
    return;
    else
    {
        print_leaves(root->left);
        if(root->left==nullptr && root->right==nullptr)
        cout<<root->data<<" ";
        print_leaves(root->right);
    }
}
node* inorder(node *root)
{
    if(root!=nullptr)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return root;
}
node* preorder(node *root)
{
    if(root!=nullptr)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);

    }
    return root;
}
node* postorder(node *root)
{
    if(root!=nullptr)
    {
        
        postorder(root->left);
        
        postorder(root->right);
        cout<<root->data<<" ";

    }
    return root;
}
void print_nodes_with_single_child(node *root)
{
    if(root!=nullptr)
    {
        print_nodes_with_single_child(root->left);
        if((root->left!=nullptr && root->right==nullptr) || (root->right!=nullptr && root->left==nullptr))
        cout<<root->data<<" ";
        print_nodes_with_single_child(root->right);
    }
}
int main()
{
    node *root=nullptr;
    while(1)
    {
        //1 100 1 357 1 237 1 152 1 389 1 367 1 38 1 39 1 -367 1 37
        int choice;
        cout<<"Press 1 to insert data : "<<endl;
        cout<<"Press 2 to delete a node : "<<endl;
        cout<<"Press 3 to inorder : "<<endl;
        cout<<"Press 4 for pre-order traversal "<<endl;
        cout<<"Press 5 for post-order traversal "<<endl;
        cout<<"Press 6 to search a key "<<endl;
        cout<<"Press 7 to find the largest in the tree"<<endl;
        cout<<"Press 8 to find the minimum element in the tree"<<endl;
        cout<<"Press 9 for second largest in the tree "<<endl;
        cout<<"Press 10 to print leaf nodes ."<<endl;
        cout<<"Press 11 nodes with single child ."<<endl;
        cout<<"Press 12 to find the Parent "<<endl;
        cout<<"Any other to exit "<<endl;
        cin>>choice;
        if(choice==1)
        {
            int data;
            cout<<"\nEnter the data to insert : ";
            cin>>data;
            root=insert_bst(root,data);
        }
        else if(choice==2)
        {
            int data;
            cout<<"\nEnter data to delete : ";
            cin>>data;
            root=delete_bst(root,data);
        }
        else if(choice==3)
        {
            cout<<endl;
            root=inorder(root);
        }
        else if(choice==4)
        {
            cout<<endl;
            root=preorder(root);
        }
        else if(choice==5)
        {
            cout<<endl;
            root=postorder(root);
        }
        else if(choice==6)
        {
            int key;
            cout<<"Enter the key to search : ";
            cin>>key;
            if(search(root,key))
            cout<<"Found"<<endl;
            else
            cout<<"Not Found"<<endl;
        }
        else if(choice==7)
        {
            cout<<"\nLargest element in the tree is  : "<<max_tree_method2(root)<<endl;
        }
        else if(choice==8)
        {
            cout<<"\nSmallest element in the tree is  : "<<min_tree(root)<<endl;
        }
        else if(choice==9)
        {
            //print_sec_lar(root);
            int c=0;
            sec_lar_method2(root,&c);
        }
        else if(choice==10)
        {
            print_leaves(root);
        }
        else if(choice==11)
        {
            print_nodes_with_single_child(root);
        }
        else if(choice==12)
        {
            int key;
            cout<<"Enter the key : ";
            cin>>key;
            find_parent(root,key,-1);
        }
        else
        {
            cout<<"___________EXIT______________";
            break;
        }
        //1 100 1 357 1 237 1 152 1 389 1 367 1 38 1 39 1 -367 1 37
    }
}
