//In this code I have tried to implement all types of rotations in an AVL tree 
//i.e. ex: LL rotation,LR rotation,RR rotation,RL rotation

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

node *LL_rotation(node *root)
{
    //This function does LL rotation on a given tree 
    node *temp_root=root;
    node *original_left=root->left;
    node *original_left_ka_right=root->left->right;
    root=original_left;
    root->right=temp_root;
    temp_root->left=original_left_ka_right;
    return root;
}
node *RR_rotation(node *root)
{
    //this function performs RR rotation on a given tree
    node *temp_root=root;
    node *original_right=root->right;
    node *original_right_ka_left=root->right->left;
    root=original_right;
    root->left=temp_root;
    temp_root->right=original_right_ka_left;
    return root;
}
node *LR_rotation(node *root)
{
    //this function does LR rotation on a given tree 
    node *orginal_root=root;
    node *LR=root->left->right;
    root->left->right=nullptr;
    node *LR_left=LR->left;
    node *LR_right=LR->right;
    root=LR;
    node *original_leftsubtree=orginal_root->left;
    root=LR;
    root->right=orginal_root;
    root->left=original_leftsubtree;
    original_leftsubtree->right=LR_left;
    orginal_root->left=LR_right;
    return root;
}
node *RL_rotation(node *root)
{
    //this function returns the node after doing the RL rotation on the tree passed as parameter
    node *original_root=root;
    node *RL=root->right->left;
    node *RL_left=RL->left;
    node *RL_right=RL->right;
    node *original_rightsubtree=original_root->right;
    original_root->right->left=nullptr;
    root=RL;
    root->left=original_root;
    root->right=original_rightsubtree;
    original_root->right=RL_left;
    original_rightsubtree->left=RL_right;
    return root;
}
int height(node *root)
{
    if(root==nullptr)
    return 0;
    else{
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
}
int balance_factor(node *root)
{
    if(root==nullptr)
    return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return lh-rh;
}
node *perform_rotations(node *root)
{
    if(root==nullptr)
    return root;
    else
    {
        int bf=balance_factor(root);
        if(bf==2)
        {
            int bf_subtree=balance_factor(root->left);
            if(bf_subtree>0)
            {
                root=LL_rotation(root);
            }
            else if(bf_subtree<0)
            {
                root=LR_rotation(root);
            }
        }
        else if(bf==-2)
        {
            int bf_subtree=balance_factor(root->right);
            if(bf_subtree>0)
            {
                root=RL_rotation(root);
            }
            else if(bf_subtree<0)
            {
                root=RR_rotation(root);
            }
        }
        node *left_subtree=perform_rotations(root->left);
        node *right_subtree=perform_rotations(root->right);
        root->left=left_subtree;
        root->right=right_subtree;
        return root;
    }
}
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
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
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
    int n;
    cout<<"Enter number of nodes in the BST : ";
    cin>>n;
    while(n--)
    {
        int data;
        cout<<"\nEnter data : ";
        cin>>data;
        root=insert_node(root,data);
    }
    cout<<"\n\nInorder traversal of the bst is : \n\n";
    inorder(root);
    cout<<"\n\nLevel order traversal of BST before modification is : \n\n";
    level_order(root);
    root=perform_rotations(root);
    cout<<"\n\nLevel order of the balanced BST is : \n\n";
    level_order(root);
}