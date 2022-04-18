//in this code I have tried to implement queue data structure using array
//this is very basic approach
#include<iostream>
using namespace std;
struct queue
{
    int size;
    int *arr;
    int front;
    int rear;
    queue(int s)
    {
        size=s;
        arr=new int[s];
        front=-1;
        rear=-1;
    }
};
int isEmpty(queue q)
{
    if(q.front==q.rear)
    return 1;
    else
    return 0;
}

int isFull(queue q)
{
    if(q.rear==q.size-1)
    return 1;
    else
    return 0;
}

void enqueue(queue &q,int x)
{
    if(isEmpty(q))//reseting pointers to save space
    {
        q.front=-1;
        q.rear=-1;
    }
    if(!isFull(q))
    {
        q.rear=q.rear+1;
        q.arr[q.rear]=x;
    }
    else
    cout<<"Queue is Full.\n";
}

void dequeue(queue &q)
{
    int x;
    if(!isEmpty(q))
    {
        x=q.arr[q.front++];
        cout<<"Element "<<x<<" dequeued succesfully.\n";
    }
    else
    cout<<"Queue is empty.\n";
}
void display(queue q)
{
    cout<<"\n";
    if(!isEmpty(q))
    {
        for(int i=q.front+1;i<=q.rear;i++)
        cout<<q.arr[i]<<" ";
        cout<<"\n";
    }
    else
    cout<<"Empty queue.\n";
}
int main()
{
    int n;
    cout<<"Enter the size of the queue : ";
    cin>>n;
    queue q(n);
    for(int i=1;i<=n;i++)
    {
        int x;
        cout<<"Enter the number to enqueue : ";
        cin>>x;
        enqueue(q,x);
    }
    while(1)
    {
        int ch;
        cout<<"Press : ";
        cout<<"1 to dequeue , and\n2 to enqueue : \n";
        cin>>ch;
        if(ch==1)
        dequeue(q);
        else if(ch==2)
        {
            int x;
            cout<<"Enter element to enqueue. : ";
            cin>>x;
            enqueue(q,x);
        }
        else 
        break;
        display(q);

        
    }
}