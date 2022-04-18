//we are implementing a minimum priority queue
#include<iostream>
using namespace std;

struct priority_queue
{
    int *arr;
    int length;
};
void initialise(priority_queue &pq)
{
    pq.arr=new int[100];
    pq.length=0;
}
void insert(priority_queue &pq,int num)
{
    if(pq.length==0)
    {
        pq.arr[pq.length++]=num;
    }
    else
    {
        pq.arr[pq.length++]=num;
        int child_index=pq.length-1;
        while(child_index>0)
        {
            int parent_index=(child_index-1)/2;
            if(pq.arr[parent_index]>pq.arr[child_index])
            {
                int temp=pq.arr[parent_index];
                pq.arr[parent_index]=pq.arr[child_index];
                pq.arr[child_index]=temp;
            }
            else
            {
                break;
            }
            child_index=parent_index;
        }
    }
}
void remove(priority_queue &pq)
{
    //we will be down heapyfying in this case
    //swap the root element with the last element
    pq.arr[0]=pq.arr[pq.length-1];
    pq.length=pq.length-1;
    int parent_index=0;
    while(parent_index<(pq.length-1))
    {
        int child1=(parent_index*2)+1;
        int child2=(parent_index*2)+2;
        bool cond=(pq.arr[parent_index]>pq.arr[child1])||(pq.arr[parent_index]>pq.arr[child2]);
        if(cond && pq.arr[child1]<pq.arr[child2])
        {
            int temp=pq.arr[parent_index];
            pq.arr[parent_index]=pq.arr[child1];
            pq.arr[child1]=temp;
            parent_index=child1;
        }
        else if(cond && pq.arr[child1]>pq.arr[child2])
        {
            int temp=pq.arr[parent_index];
            pq.arr[parent_index]=pq.arr[child2];
            pq.arr[child2]=temp;
            parent_index=child2;
        }
        else
        {
            break;
        }
    }
}
void print_pq(priority_queue &pq)
{
    cout<<endl;
    for(int i=0;i<pq.length;i++)
    {
        cout<<pq.arr[i]<<" ";
    }
}
int main()
{
    priority_queue pq;
    initialise(pq);
    while(1)
    {
        int choice;
        cout<<"Press 1 to insert a value in priority queue.\n";
        cout<<"Press 2 to remove minimum element from priority queue.\n";
        cout<<"Press 3 to get minimum element from priority queue.\n";
        cout<<"Enter your choice.\n";
        cin>>choice;
        if(choice==1)
        {
            int num;
            cout<<"Enter the number you want to insert into priority queue : ";
            cin>>num;
            insert(pq,num);
            //print_pq(pq);
        }
        else if(choice==2)
        {
            cout<<"\nBefore : \n";
            print_pq(pq);
            remove(pq);
             cout<<"\nAfter : \n";
            print_pq(pq);
        }
        else
        {
            break;
        }
    }

}