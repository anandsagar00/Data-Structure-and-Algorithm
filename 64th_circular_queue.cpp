//In this code I have tried to implement circular queue using array

#include<iostream>
using namespace std;

struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
    queue(int siz)
    {
        front=0;
        rear=0;
        size=siz+1;//as one space will remain vacant in queue
        arr=new int[size];
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
    if((q.rear+1)%q.size==q.front)
    return 1;
    else 
    return 0;
}

void enqueue(queue &q,int x)
{
    if(!isFull(q))
    {
        q.rear=(q.rear+1)%q.size;
        q.arr[q.rear]=x;
    }
    else
    cout<<"\nQueue is FULL.\n";
}

void dequeue(queue &q)
{
    int x;
    if(!isEmpty(q))
    {
        q.front=(q.front+1)%q.size;
        x=q.arr[q.front];
        //cout<<x<<" ";
        cout<<"\n"<<x<<" dequeued succesfully.\n";
    }
    else
    cout<<"\nQueue is Empty.\n";
}
void display(queue q)
{
    while(q.front!=q.rear)
    {
        q.front=(q.front+1)%q.size;
        cout<<q.arr[q.front]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter size of queue : ";
    cin>>n;
    queue q(n);
    for(int i=1;i<=n;i++)
    {
        int x;
        cout<<"Enter value to enqueue : ";
        cin>>x;
        enqueue(q,x);
    }
    while(1)
    {
        int ch;
        cout<<"Press : ";
        cout<<"1 to dequeue , and\n2 to enqueue : \nany other to exit\n: ";
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

