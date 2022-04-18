#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct Account
{
    char name[10];
    int account_no;
    char acc_type[5];
    float balance;
    struct Account *left;
    struct Account *right;
}node;

typedef struct Account_copy
{
    char name[10];
    int account_no;
    char acc_type[5];
    float balance;
}acc_copy;

node *insert(node *root,char name[],int account_no,char acc_type[],float balance)
{
    if(root==NULL)
    {
        node *temp=(node *)malloc(sizeof(node));
        temp->left=NULL;
        temp->right=NULL;
        strcpy(temp->name,name);
        strcpy(temp->acc_type,acc_type);
        temp->balance=balance;
        temp->account_no=account_no;
        return temp;
    }
    else
    {
        if(account_no<root->account_no)
        root->left=insert(root->left,name,account_no,acc_type,balance);
        else if(account_no>root->account_no)
        root->right=insert(root->right,name,account_no,acc_type,balance);
        else
        return root;
        return root;
    }
}
int height(node *root)
{
    if(root==NULL)
    return 0;
    else
    {
        int left=height(root->left);
        int right=height(root->right);
        return left>right?left+1:right+1;
    }
}
acc_copy in_pre(node *root)
{
    node *temp=root;
    while(temp->right!=NULL)
    temp=temp->right;
    acc_copy a;
    strcpy(a.acc_type,temp->acc_type);
    strcpy(a.name,temp->name);
    a.account_no=temp->account_no;
    a.balance=temp->balance;
    return a;
}
acc_copy in_succ(node *root)
{
    node *temp=root;
    while(temp->left!=NULL)
    temp=temp->left;
    acc_copy a;
    strcpy(a.acc_type,temp->acc_type);
    strcpy(a.name,temp->name);
    a.account_no=temp->account_no;
    a.balance=temp->balance;
    return a;
}
node *delete_bst(node *root,int account_no)
{
    if(root==NULL)
    return NULL;
    else if(root->left==NULL && root->right==NULL && root->account_no==account_no)
    return NULL;
    else 
    {
        if(account_no<root->account_no)
        root->left=delete_bst(root->left,account_no);
        else if(account_no>root->account_no)
        root->right=delete_bst(root->right,account_no);
        else
        {
            int lh=height(root->left);
            int rh=height(root->right);
            if(lh>rh)
            {
                acc_copy in_pred=in_pre(root->left);
                strcpy(root->acc_type,in_pred.acc_type);
                strcpy(root->name,in_pred.name);
                root->account_no=in_pred.account_no;
                root->balance=in_pred.balance;
                root->left=delete_bst(root->left,root->account_no);
            }
            else
            {
                acc_copy in_succe=in_succ(root->left);
                strcpy(root->acc_type,in_succe.acc_type);
                strcpy(root->name,in_succe.name);
                root->account_no=in_succe.account_no;
                root->balance=in_succe.balance;
                root->right=delete_bst(root->right,root->account_no);
            }
            return root;
        }
        return root;
    }
}
int search(node *root,int account_no)
{
    if(root==NULL)
    {
        printf("\nSearch Unsuccesfull\n");
    }
    else
    {
        int left=0;
        int right=0;
        if(account_no<root->account_no)
        left=search(root->left,account_no);
        else if(account_no>root->account_no)
        right=search(root->right,account_no);
        else
        {
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
            return 1;
        }
        if(left==1 || right==1)
        return 1;
        else
        return 0;
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
            preorder(root->left);
            preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
            postorder(root->left);
            postorder(root->right);
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
    }
}
int max_bal_acc(node *root)
{
    if(root==NULL)
    return INT_MIN;
    else
    {
        int left=max_bal_acc(root->left);
        int right=max_bal_acc(root->right);
        int root_bal=root->balance;
        if(root_bal>left && root_bal>right)
        return root_bal;
        else if(left>root_bal && left>right)
        return left;
        else 
        return right;
    }
}
void print_max_bal(node *root,int max_bal)
{
    if(root==NULL)
    return;
    else
    {
        print_max_bal(root->left,max_bal);
        if(root->balance==max_bal)
        {
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
        }
        print_max_bal(root->right,max_bal);
    }
}
int min_bal_acc(node *root)
{
    if(root==NULL)
    return INT_MAX;
    else
    {
        int left=min_bal_acc(root->left);
        int right=min_bal_acc(root->right);
        int root_bal=root->balance;
        if(root_bal<left && root_bal<right)
        return root_bal;
        else if(left<root_bal && left<right)
        return left;
        else 
        return right;
    }
}
void print_min_bal(node *root,int min_bal)
{
    if(root==NULL)
    return;
    else
    {
        print_min_bal(root->left,min_bal);
        if(root->balance==min_bal)
        {
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
        }
        print_min_bal(root->right,min_bal);
    }
}
void print_less_than_500(node *root)
{
    if(root==NULL)
    return;
    else
    {
        print_less_than_500(root->left);
        if(root->balance<500)
        {
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
        }
        print_less_than_500(root->right);
    }
}
void print_ancestor(node *root,int account_no)
{
    if(root==NULL)
    return;
    else
    {
        if(account_no<root->account_no)
        {
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
            print_ancestor(root->left,account_no);
        }
        else if(account_no>root->account_no)
        {
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
            print_ancestor(root->right,account_no);
        }
        else
        return;
    }
}
void level(node *root,int account_no,int level_node)
{
    if(root==NULL)
    {
        printf("\nkey not found.\n");
        return;
    }
    else
    {
        if(account_no<root->account_no)
        level(root->left,account_no,level_node+1);
        else if(account_no>root->account_no)
        level(root->right,account_no,level_node+1);
        else
        {
            printf("Level of node is : %d .\n",level_node);
        }
    }
}
void left_view(node *root)
{
    if(root!=NULL)
    {
        left_view(root->left);
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
    }
}
void right_view(node *root)
{
    if(root!=NULL)
    {
        right_view(root->right);
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
    }
}
void largest_bst(node *root)
{
    inorder(root);
}
void top_view(node *root)
{
    if(root==NULL)
    return;
    else if(root->left==NULL && root->right==NULL)
    {
            printf("\nName : %s\n",root->name);
            printf("Account Number : %d\n",root->account_no);
            printf("Account type : %s\n",root->acc_type);
            printf("Balance : %f\n",root->balance);
    }
    else
    {
        top_view(root->left);
        top_view(root->right);
    }
}
void bottom_view(node *root)
{
    if(root==NULL)
    return ;
    else
    {
            if(root->left!=NULL && root->right!=NULL)
            {
                printf("\nName : %s\n",root->name);
                printf("Account Number : %d\n",root->account_no);
                printf("Account type : %s\n",root->acc_type);
                printf("Balance : %f\n",root->balance);
            }
            bottom_view(root->left);
            bottom_view(root->right);
    }
}
void print_left_right_subtree(node *root,int account_no)
{
    if(root==NULL)
    return;
    else
    {
        if(account_no<root->account_no)
        print_left_right_subtree(root->left,account_no);
        else if(account_no>root->account_no)
        print_left_right_subtree(root->right,account_no);
        else
        {
            printf("\nLeft subtree is : \n");
            inorder(root->left);
            printf("\nRight subtree is : \n");
            inorder(root->right);
            return;
        }
    }
}
node *root_copy=NULL;
void same_balance_printf(node *root,float bal)
{
    if(root!=NULL)
    {
        if(root->balance==bal)
        {
            printf("\nName : %s\n",root->name);
                printf("Account Number : %d\n",root->account_no);
                printf("Account type : %s\n",root->acc_type);
                printf("Balance : %f\n",root->balance);
        }
        same_balance_printf(root->left,bal);
        same_balance_printf(root->right,bal);
    }
}
void same_bal(node *root)
{
    if(root!=NULL)
    {
        same_balance_printf(root_copy,root->balance);
        same_bal(root->left);
        same_bal(root->right);
    }
}
int main()
{
    node *root=NULL;
    while(1)
    {
        int choice;
        printf("\nPress 1 for insert.\n");
        printf("\nPress 2 for search.\n");
        printf("\nPress 3 for delete.\n");
        printf("\nPress 4 for inorder traversal.\n");
        printf("\nPress 5 for preorder traversal.\n");
        printf("\nPress 6 for postorder traversal.\n");
        printf("\nPress 7 for same balance\n");
        printf("\nPress 8 highest balance\n");
        printf("\nPress 9 minimum balance\n");
        printf("\nPress 10 for less than 500.\n");
        printf("\nPress 11 level of a node.\n");
        printf("\nPress 12 all ancestors of a node.\n");
        printf("\nPress 13 for top view.\n");
        printf("\nPress 14 for bottom view.\n");
        printf("\nPress 15 for left view.\n");
        printf("\nPress 16 for right view.\n");
        printf("Press 17 to Search a key and print its left and right subtree\n");
        printf("Press 18 to Largest subtree in the BST\n");
        printf("Press 19 to exit.\n\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            int account_no;
            char name[10];
            char account_type[5];
            float balance;
            printf("Enter account number : ");
            scanf("%d",&account_no);
            printf("\nName : \n");
            fflush(stdin);
            scanf("%s",name);
            fflush(stdin);
            printf("\nAccount type : \n");
            fflush(stdin);
            scanf("%s",account_type);
            fflush(stdin);
            printf("\nEnter balance : \n");
            scanf("%f",&balance);
            root=insert(root,name,account_no,account_type,balance);
        }
        else if(choice==2)
        {
            int acc_no;
            printf("\nEnter accoount number to search : ");
            scanf("%d",&acc_no);
            if(search(root,acc_no))
            {

            }
            else
            {
                printf("\nThis account number doesn't exist.\n");
            }
        }
        else if(choice==3)
        {
            int acc_no;
            printf("Enter account number to delete : ");
            scanf("%d",&acc_no);
            root=delete_bst(root,acc_no);
        }
        else if(choice==4)
        inorder(root);
        else if(choice==5)
        preorder(root);
        else if(choice==6)
        postorder(root);
        else if(choice==7)
        {
            root_copy=root;
            same_bal(root);
        }
        else if(choice==8)
        {
            int max_balance=max_bal_acc(root);
            print_max_bal(root,max_balance);
        }
        else if(choice==9)
        {
            int min_balance=min_bal_acc(root);
            print_min_bal(root,min_balance);
        }
        else if(choice==10)
        {
            print_less_than_500(root);
        }
        else if(choice==11)
        {
            int account_no;
            printf("Enter key/account number : ");
            scanf("%d",&account_no);
            printf("\n");
            level(root,account_no,0);
        }
        else if(choice==12)
        {
            int acc_no;
            printf("Enter account number : ");
            scanf("%d",&acc_no);
            print_ancestor(root,acc_no);
        }
        else if(choice==13)
        {
            top_view(root);
        }
        else if(choice==14)
        {
            bottom_view(root);
        }
        else if(choice==15)
        {
            left_view(root);
        }
        else if(choice == 16)
        {
            right_view(root);
        }
        else if(choice==17)
        {
            int account_no;
            printf("Enter key : ");
            scanf("%d",&account_no);
            print_left_right_subtree(root,account_no);
        }
        else if(choice==18)
        {
            largest_bst(root);
        }
        else if(choice==19)
        {
            printf("__________EXIT_________");
            break;
        }
        else
        {
            printf("\nWrong choice.\n");
        }

    }
}


