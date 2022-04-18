//implement n-ary tree 
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    vector<node *> children;
    node(int x)
    {
        data=x;
    }
};

node *take_input(node *root)
{
    int x;
    cout<<"Enter data : ";
    cin>>x;
    root=new node(x);
    queue <node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        int num;
        cout<<"Enter number of children of "<<temp->data<<" node : ";
        cin>>num;
        for(int i=1;i<=num;i++)
        {
            int nth_node_of_temp;
            cout<<"Enter node number "<<i<<" of "<<temp->data<<" node : ";
            cin>>nth_node_of_temp;
            node *new_temp=new node(nth_node_of_temp);
            q.push(new_temp);
            temp->children.push_back(new_temp);
        }
    }
    return root;
}
void tree_traversal_level_order(node *root)
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        cout<<temp->data<<":";
        vector<node *>v=temp->children;
        int i=0;
        while(i<v.size())
        {
            q.push(v[i]);
            cout<<v[i]->data<<",";
            i++;
        }
        cout<<endl;

    }

}
int main()
{
    node *root=nullptr;
    root=take_input(root);
    tree_traversal_level_order(root);
}