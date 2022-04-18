/*
Problem Statement: Delete every N nodes
Problem Level: MEDIUM
Problem Description:
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.'
Traverse the linked list such that you retain the 'M' nodes,
then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= P <= 10^5
Where P is the size of the singly linked list.
0 <= M <= 10^5
0 <= N <= 10^5

Time Limit: 1sec

Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2

Sample Output 1 :
1 2 5 6

Sample Input 2 :
2
10 20 30 40 50 60 -1
0 1
1 2 3 4 5 6 7 8 -1
2 3

Sample Output 2 :
1 2 6 7

Explanation of Sample Input 2 :
For the first query, we delete one node after every zero elements hence removing all the items of the list. Therefore, nothing got printed.

For the second query, we delete three nodes after every two nodes, resulting in the final list, 1 -> 2 -> 6 -> 7.
*/

#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next=nullptr;
    }
};
node *append(node *head)
{
    int data;
    cout<<"Enter data : ";
    cin>>data;
    //now we will create a temporary node
    node *temp=new node(data);
    if(head==nullptr)
    {
        head=temp;
    }
    else
    {
        node *p=head;
        while(p->next!=nullptr)
        p=p->next;
        p->next=temp;
    }
    return head;
}
void recur_traversal(node *head)
{
    if(head==nullptr)
    return;
    cout<<head->data<<" ";
    recur_traversal(head->next);
}
//include_ tells how many nodes to include and delete_ tells how many nodes to delete
node *new_list(node *head,int include_,int delete_)
{
    node *final_list=nullptr;
    node *ptr=nullptr;
    node *p=head;
    int include_copy=include_;
    int delete_copy=delete_;
    while(p!=nullptr)
    {
        include_=include_copy;
        delete_=delete_copy;
        //this loops includes the nodes in final list
        while(include_-- && p!=nullptr)
        {
            if(final_list==nullptr)
            {
                final_list=p;
                ptr=final_list;
                p=p->next;
            }
            else
            {
                ptr->next=p;
                p=p->next;
                ptr=ptr->next;
                ptr->next=nullptr;
            }
        }
        //this loop excludes the nodes from the final list
        while(delete_-- && p!=nullptr)
        {
            p=p->next;
        }

    }
    return final_list;
}
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    node *head=nullptr;
    while(n--)
    {
        head=append(head);
    }
    int delete_,include_;
    cout<<"\nEnter number of nodes to include : 🤪 ";
    cin>>include_;
    cout<<"\nEnter number of nodes to delete : ";
    cin>>delete_;
    cout<<"\nOLD LIST : \n";
    recur_traversal(head);
    
    head=new_list(head,include_,delete_);
    cout<<"\nNEW LIST : \n";
    recur_traversal(head);
}