/*
Problem Statement: Swap two Nodes of LL
Problem Level: MEDIUM
Problem Description:
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th'  and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4

Sample Output 1 :
3 4 5 6 2 1 9

Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6

Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70
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
node *swap_nodes(node *head,int i1,int j1)
{
    //here I am setting i to lower index
    int i,j;
    if(i1==j1)
    return head;
    else if(i1>j1)
    {
        j=i1;
        i=j1;
    }
    else
    {
        i=i1;
        j=j1;
    }
    //previous and current pointers for two nodes
    node *p=head;
    node *p1=nullptr;
    node *p2=nullptr;
    node *c1=head;
    node *c2=head;
    int node_number=0;
    while(p!=nullptr)
    {
       if(node_number<i)
       {
           p1=c1;
           c1=c1->next;
       }
       if(node_number<j)
       {
           p2=c2;
           c2=c2->next;
       }
       if(node_number==j && i!=0 && j-i>1)//if nodes aren't adjacent and no fisrt node
       {
           //t1 t2 are temp variables to store data of next nodes of both the current nodes
           node *t1=c1->next;
           node *t2=c2->next;
           p1->next=c2;
           c2->next=t1;
           p2->next=c1;
           c1->next=t2;
           break;
       }
       else if(node_number==j && i!=0 && j-i==1)//when nodes are adjacent but not first nodes
       {
           node *t2=c2->next;
           p1->next=c2;
           c2->next=c1;
           c1->next=t2;
           break;
       }
       else if(node_number==j && i==0 && j-i>1)//first node but nodes aren't adjacent
       {
           node *t1=c1->next;
           node *t2=c2->next;
           head=c2;
           c2->next=t1;
           p2->next=c1;
           c1->next=t2;
           break;
       }
       else if(node_number==j && i==0 && j-i==1)//swap first two nodes
       {
           node *t2=c2->next;
           head=c2;
           c2->next=c1;
           c1->next=t2;
           break;
       }
       p=p->next;
       node_number++;  
    }
    return head;

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
    int i,j;
    cout<<"\nEnter the first index of node ";
    cin>>i;
    cout<<"\nEnter the index of node you want to swap with ";
    cin>>j;
    cout<<"\nOLD LIST : \n";
    recur_traversal(head);
    
    head=swap_nodes(head,i,j);
    cout<<"\nNEW LIST : \n";
    recur_traversal(head);
}