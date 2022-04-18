//creating two stacks and performing basic operations
#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int *arr;
    int size;
    int top;
}stack;

void push(stack *s,int data)
{
    if(s->top==s->size-1)
    {
        printf("\nStacck already full.");
    }
    else
    {
        s->top=s->top+1;
        s->arr[s->top]=data;
    }
}
void pop(stack *s)
{
    if(s->top!=-1)
    {
        s->top=s->top-1;
    }
    else
    {
        printf("\nStack is already empty.");
    }
}
int peek(stack s)
{
    if(s.top!=-1)
    return s.arr[s.top];
}
int main()
{
    stack s1;
    stack s2;
    s1.top=-1;
    s2.top=-1;
    printf("Enter number of elemets in stacks : ");
    int size;
    scanf("%d",&size);
    s1.size=size;
    s2.size=size;
    s1.arr=(int *)malloc(sizeof(int)*size);
    s2.arr=(int *)malloc(sizeof(int)*size);
    
    for(int i=1;i<=size;i++)
    {
        printf("\nElements in first stack1 : \n");
        int data;
        scanf("%d",&data);
        push(&s1,data);
        printf("Enter data in stack2 : \n");
        scanf("%d",&data);
        push(&s2,data);
    }
}