//problem 3 (implement dictionary using BST)
//Name : ANAND SAGAR
//USN : 01fe20bcs327
//Roll : 564
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//this is the structure of node of dictionary which will store value corresponding to a key.
typedef struct node
{
    char key[30];
    char value[30];
    struct node *left;
    struct node *right;
} node;

node *insert_in_bst(node *root, char key[], char value[])
{
    if (root == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        strcpy(temp->key, key);
        strcpy(temp->value, value);
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else
    {
        //if the string is lesser then the root node's string go to left other wise go to right and if equal then return
        int difference = strcmp(key, root->key);
        if (difference < 0)
            root->left = insert_in_bst(root->left, key, value);
        else if (difference > 0)
            root->right = insert_in_bst(root->right, key, value);
        else
        {
            return root;
        }
        return root;
    }
}
void inorder(node *root)
{
    //this function performs inorder traversal over a given BST and displays the key value pair in sorted order a/c to key
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s : %s\n", root->key, root->value);
        inorder(root->right);
    }
}
void search(node *root, char key[])
{
    //this function searches if a key is present or not
    //if a key is present it prints its value other wise prints KEY is not present.
    if (root == NULL)
    {
        printf("\nKEY is not found.\n");
    }
    else
    {
        int diff = strcmp(key, root->key);
        if (diff > 0)
            search(root->right, key);
        else if (diff < 0)
            search(root->left, key);
        else if (diff == 0)
        {
            printf("\nValue at KEY %s is %s .\n", root->key, root->value);
        }
    }
}
int height(node *root)
{
    //this function returns the height of a given binary tree
    if (root == NULL)
        return 0;
    else
    {
        //l and r denotes the height of left subtree and right subtree respectively
        int l, r;
        l = height(root->left);
        r = height(root->right);
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
}
node *pre(node *root)
{
    //this function returns the inorder predecessor of of a node when its left subtree is passed.
    node *temp = NULL;
    while (root != NULL)
    {
        temp = root;
        root = root->right;
    }
    return temp;
}
node *succ(node *root)
{
    //this function returns the inorder succesor of the node when its right subtree is passed.
    node *temp = NULL;
    while (root != NULL)
    {
        temp = root;
        root = root->left;
    }
    return temp;
}
node *delete_key(node *root, char key[])
{
    // If the height of left subtree is greater than the right then we will replace by inorder predecessor else by inorder succesor
    if (root == NULL)
    {
        printf("\nKey Not Found.\n");
        return NULL;
    }
    else if (strcmp(key, root->key) == 0 && root->left == NULL && root->right == NULL)
    {
        return NULL;
    }
    else
    {
        int diff = strcmp(key, root->key);
        if (diff < 0)
            root->left = delete_key(root->left, key);
        else if (diff > 0)
            root->right = delete_key(root->right, key);
        else
        {
            int left_height = height(root->left);
            int right_height = height(root->right);
            if (left_height > right_height)
            {
                node *predecessor = pre(root->left);
                strcpy(root->key, predecessor->key);
                strcpy(root->value, predecessor->value);
                root->left = delete_key(root->left, predecessor->key);
            }
            else
            {
                node *succsesor = succ(root->right);
                strcpy(root->key, succsesor->key);
                strcpy(root->value, succsesor->value);
                root->right = delete_key(root->right, succsesor->key);
            }
            return root;
        }
        return root;
    }
}
int main()
{
    node *root = NULL;
    printf("Keep on Entering ingriends until all required Ingredients are fullfilled.\n");
    while (1)
    {
        int ch;
        printf("\nPress 1 to insert.\nPress 2 to search.\nPress 3 for inorder traversal.\nPress 4 for deleting a key from Dict.\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            char key[30];
            char value[30];
            fflush(stdin);
            printf("\nEnter key value : ");
            fflush(stdin);
            scanf("%s", key);
            fflush(stdin);
            printf("Enter value corresponding to %s : ", key);
            fflush(stdin);
            scanf("%s", value);
            fflush(stdin);
            root = insert_in_bst(root, key, value);
        }
        else if (ch == 2)
        {
            char key[30];
            printf("Enter key value to search : ");
            fflush(stdin);
            scanf("%s", key);
            fflush(stdin);
            search(root, key);
        }
        else if (ch == 3)
            inorder(root);
        else if (ch == 4)
        {
            char key[30];
            printf("Enter the key you want to delete : ");
            scanf("%s", key);
            printf("\n");
            root = delete_key(root, key);
        }
        else
            break;
    }
}