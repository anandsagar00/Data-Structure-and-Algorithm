#include<iostream>
using namespace std;
struct node
{
    int sensor_id;
    float time_stamp;
    float heat_value;
    node *left;
    node *right;
    node(int si,float ts,float hv)
    {
        sensor_id=si;
        time_stamp=ts;
        heat_value=hv;
        left=nullptr;
        right=nullptr;
    }
};

node *create_node(int si,float ts,float hv)
{
    node *temp=new node(si,ts,hv);
    return temp;
}

void print_node(node *root)
{
    if(root!=nullptr)
    {
        cout<<"sensor id : "<<root->sensor_id<<endl;
        cout<<"time stamp : "<<root->time_stamp<<endl;
        cout<<"Heat value : "<<root->heat_value<<endl;
        cout<<endl;
    }
}

node *insert_node(node *root,int si,float ts,float hv)
{
    if(root==nullptr)
    {
        node *temp=create_node(si,ts,hv);
        return temp;
    }
    else
    {
        if(hv<root->heat_value)
        {
            root->left=insert_node(root->left,si,ts,hv);
        }
        else if(hv>root->heat_value)
        {
            root->right=insert_node(root->right,si,ts,hv);
        }
        else
        {
            root->heat_value=hv;
            return root;
        }
        return root;
    }
}
bool search(node *root,float key_heat_value)
{
    if(root==nullptr)
    return false;
    else
    {
        bool state=false;
        if(key_heat_value<root->heat_value)
        state=search(root->left,key_heat_value);
        else if(key_heat_value>root->heat_value)
        state=search(root->right,key_heat_value);
        else
        {
            print_node(root);
            return true;
        }
        return state;
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
struct copy_node
{
    int s_id;
    float ts;
    float hv;
};

copy_node max_in_left(node *root)
{
    node *temp=root;
    while(temp->right!=nullptr)
    temp=temp->right;
    copy_node cn;
    cn.s_id=temp->sensor_id;
    cn.hv=temp->heat_value;
    cn.ts=temp->time_stamp;
    return cn;
}
copy_node min_in_right(node *root)
{
    node *temp=root;
    while(temp->left!=nullptr)
    temp=temp->left;
    copy_node cn;
    cn.s_id=temp->sensor_id;
    cn.hv=temp->heat_value;
    cn.ts=temp->time_stamp;
    return cn;
}
node *delete_bst(node *root,float hv)
{
    if(root==nullptr)
    return root;
    else if(root->heat_value==hv && root->left==nullptr && root->right==nullptr)
    {
        delete root;
        return nullptr;
    }
    else
    {
        if(hv<root->heat_value)
        root->left=delete_bst(root->left,hv);
        else if(hv>root->heat_value)
        root->right=delete_bst(root->right,hv);
        else
        {
            int lh=height(root->left);
            int rh=height(root->right);
            if(lh>rh)
            {
                //we will delete from left
                copy_node cn=max_in_left(root->left);
                root->sensor_id=cn.s_id;
                root->time_stamp=cn.ts;
                root->heat_value=cn.hv;
                root->left=delete_bst(root->left,root->heat_value);
            }
            else
            {
                copy_node cn=min_in_right(root->right);
                root->sensor_id=cn.s_id;
                root->time_stamp=cn.ts;
                root->heat_value=cn.hv;
                root->right=delete_bst(root->right,root->heat_value);
            }
            return root;
        }
        return root;
    }
}
node* inorder(node *root)
{
    if(root!=nullptr)
    {
        inorder(root->left);
        print_node(root);
        inorder(root->right);
        return root;
    }
    else 
    return nullptr;
}
node* preorder(node *root)
{
    if(root!=nullptr)
    {
        print_node(root);
        preorder(root->left);
        preorder(root->right);
        return root;
    }
    else 
    return nullptr;
}
node* postorder(node *root)
{
    if(root!=nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        print_node(root);
        return root;
    }
    else 
    return nullptr;
}
bool display_heat_value(node *root,int sid)
{
    if(root==nullptr)
    return false;
    else
    {
        bool l,r,c;
        l=display_heat_value(root->left,sid);
        r=display_heat_value(root->right,sid);
        if(root->sensor_id==sid)
        {
            print_node(root);
            c=true;
            return true;
        }
        return l||r||c;
    }
}
void time_stamp_highest(node *root,int &c)
{
    if(root==nullptr || c>=1)
    {
        return;
    }
    else
    {
        time_stamp_highest(root->right,c);
        c++;
        if(c==1)
        {
            cout<<"Time stamp of sensor with highest heat value is : "<<root->time_stamp<<endl;
        }
        time_stamp_highest(root->left,c);
    }
}
void display_threshold(node *root,float thv)
{
    if(root!=nullptr)
    {
        display_threshold(root->left,thv);
        if(root->heat_value>=thv)
        {
            cout<<"Time stamp : "<<root->time_stamp<<endl;
        }
        display_threshold(root->right,thv);
    }
}

void print_level(node *root,int level,float hv)
{
    if(root==nullptr)
    {
        cout<<"\nKey not found.\n";
    }
    else 
    {
        if(hv<root->heat_value)
        print_level(root->left,level+1,hv);
        else if(hv>root->heat_value)
        print_level(root->right,level+1,hv);
        else
        {
            cout<<"\nLevel of node is "<<level<<endl;
            return;
        }
    }
}

void print_ancestors(node *root,float hv)
{
    if(root!=nullptr)
    {
        if(hv<root->heat_value)
        {
            print_node(root);
            print_ancestors(root->left,hv);
        }
        else if(hv>root->heat_value)
        {
            print_node(root);
            print_ancestors(root->right,hv);
        }
        else
        return;
    }
}
void print_both_subtrees(node *root,float hv)
{
    if(root==nullptr)
    {
        cout<<"Key not found"<<endl;
        return;
    }
    else
    {
        if(hv<root->heat_value)
        print_both_subtrees(root->left,hv);
        else if(hv>root->heat_value)
        print_both_subtrees(root->right,hv);
        else
        {
            if(root->left!=nullptr)
            {
            cout<<"Left subtree is : "<<endl;
            inorder(root->left);
            }
            else
            {
                cout<<"There is no left subtree."<<endl;
            }
            if(root->right!=nullptr){
            cout<<"Right subtree is : "<<endl;
            inorder(root->right);
            }
            else 
            {
                cout<<"There is no right subtree."<<endl;            
            }
            return;
        }
    }
}
int count_nodes(node *root)
{
    if(root==nullptr)
    return 0;
    else
    {
        int l=count_nodes(root->left);
        int r=count_nodes(root->right);
        return l+r+1;
    }
}
void find_largest_subtree(node *root)
{
    int ls=count_nodes(root->left);
    int rs=count_nodes(root->right);
    if(ls>rs)
    {
        cout<<"Largest subtree is  : "<<endl;
        inorder(root->left);
    }
    else
    {
         cout<<"Largest subtree is  : "<<endl;
        inorder(root->right);
    }
}
int main()
{
    node *root=nullptr;
    while(1)
    {
        int choice;
        cout<<"Press 1 to insert\nPress 2 to search\nPress 3 to delete\nPress 4 to inorder traversal\n ";
        cout<<"Press 5 to preorder\nPress 6 to postorder\nPress 7 to display heat value of given sensor\n";
        cout<<"Press 8 to display time stamp greater than threshold value\nPress 9 to find level of a given node\n";
        cout<<"Press 10 to print time stamp of sensor with highest heat value.\nPress 11 to print all ancestors\n";
        cout<<"Press 12 to print left and right subtree of a key.\nPress 13 to find the largest subtree.\n";
        cout<<"Press 14 to exit.\n";
        cout<<"Enter your choice.\n";
        cin>>choice;
        if(choice==1)
        {
            int sid;
            float ts,hv;
            cout<<"Enter sensor id : ";
            cin>>sid;
            cout<<"Enter time stamp : ";
            cin>>ts;
            cout<<"Enter heat value : ";
            cin>>hv;
            root=insert_node(root,sid,ts,hv);
        }
        else if(choice==2)
        {
            float hv;
            cout<<"\nEnter heat value to search : ";
            cin>>hv;
            bool isFound=search(root,hv);
            if(!isFound)
            cout<<"\nKey not found.\n";
        }
        else if(choice==3)
        {
            float hv;
            cout<<"\nEnter heat value to delete : ";
            cin>>hv;
            root=delete_bst(root,hv);
        }
        else if(choice==4)
        {
            root=inorder(root);
        }
        else if(choice==5)
        {
            root=preorder(root);
        }
        else if(choice==6)
        {
            root=preorder(root);
        }
        else if(choice==7)
        {
            int sid;
            cout<<"\nEnter sensor id : ";
            cin>>sid;
            display_heat_value(root,sid);
        }
        else if(choice==8)
        {
            float thv;
            cout<<"\nEnter threshold value : ";
            cin>>thv;
            display_threshold(root,thv);
        }
        else if(choice==9)
        {
            float hv;
            cout<<"\nEnter heat value : ";
            cin>>hv;
            print_level(root,0,hv);
        }
        else if(choice==10)
        {
            int c=0;
            time_stamp_highest(root,c);
        }
        else if(choice==11)
        {
            float hv;
            cout<<"Enter heat value : ";
            cin>>hv;
            print_ancestors(root,hv);
        }
        else if(choice==12)
        {
            float hv;
            cout<<"\nEnter key heat value : ";
            cin>>hv;
            print_both_subtrees(root,hv);
        }
        else if(choice==13)
        {
            find_largest_subtree(root);
        }
        else if(choice==14)
        {
            cout<<"\n______________________EXIT_____________________________\n";
            break;
        }
        else
        {
            cout<<"\nWrong choice\n";
        }
    }
}