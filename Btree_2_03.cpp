//find the diameter of the binary tree
//In this question I have created a binary tree using level order traversal and I have printed its preorder traversal and
//I have also printed the diameter of the tree.

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void create_tree(node *&root)
{
    int data;
    cout << "Enter the value in root node : ";
    cin >> data;
    root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *front_of_q = q.front();
        q.pop();
        cout << "Enter left child of " << front_of_q->data << " : ";
        cin >> data;
        if (data >= 0)
        {
            node *left_child = new node(data);
            front_of_q->left = left_child;
            q.push(left_child);
        }
        cout << "Enter right child of " << front_of_q->data << " : ";
        cin >> data;
        if (data >= 0)
        {
            node *right_child = new node(data);
            front_of_q->right = right_child;
            q.push(right_child);
        }
    }
}
int height(node *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int left_heigth = height(root->left);
        int right_height = height(root->right);
        if (left_heigth > right_height)
            return 1 + left_heigth;
        else
            return 1 + right_height;
    }
}
int maxoftwo(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int diameter(node *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int left_subtree_height = height(root->left);
        int right_subtree_height = height(root->right);
        int left_diameter = diameter(root->left);
        int right_diameter = diameter(root->right);
        int lhPlusRh = left_subtree_height + right_subtree_height;
        return maxoftwo(lhPlusRh + 1, maxoftwo(left_diameter, right_diameter));
    }
}
void preorder(node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    node *root = nullptr;
    create_tree(root);
    cout << "\n\nPreoder traversal : \n";
    preorder(root);
    cout << "\n\nDiameter of the given tree is : " << diameter(root);
}