#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 5

struct indices
{
    int front1;  //Producer
    int rear1;
    int front2;  //Consumer
    int rear2;
    int produce;
    int consume;
};

struct production_consumption
{
    int data[MAXQUEUE];
    struct indices temp;
};

typedef struct production_consumption prod_cons;

int main()
{
    prod_cons p,q;
    q.temp.front1=0;
    q.temp.rear1=-1;
    q.temp.consume=0;
    q.temp.produce=0;
    p.temp.front2=0;
    p.temp.rear2=-1;
    p.temp.consume=0;
    p.temp.produce=0;
    int opn;
    while(1)
    {
        printf("\n1-Produce_in_Producer\n2-Consume_from_Consumer\n3-Produce_in_Consumer\n4-Consume_from_Producer\n5-Print_Producer_Consumer\n6-activeprod_consumer\n7-Exit\n");
        scanf("%d", &opn);
        switch(opn)
        {
        case 1: Produce_in_Produce(&q);
                break;
        case 2: Consume_from_Consume(&p);
                break;
        case 3: Produce_in_Consume(&p);
                break;
        case 4: Consume_from_Produce(&q);
                break;
        case 5: Print_Producer_Consumer(q,p);
                break;
        case 6: activeprod_consumer(q,p);
                break;
        case 7: printf("exiting\n");
                exit(0);

        }
    }
}

int full(prod_cons* q)
{
    if(q->temp.rear1==MAXQUEUE-1){
        return 1;
    }else{
        return 0;
    }
}

void Produce_in_Produce(prod_cons* q)
{
    if(full(q)){
        printf("Stack full\n");
        return;
    }
    q->temp.produce=1;
    int lower = 1, upper = 100;
    printf("Data entered into queue produce\n");
    int num = (rand() % (upper - lower + 1)) + lower;
    q->data[++q->temp.rear1] = num;
}

void Produce_in_Consume(prod_cons* q)
{
    if(full(q)){
        printf("Stack full\n");
        return;
    }
    q->temp.produce=1;
    int lower = 100, upper = 200;
    printf("Data entered into queue consume\n");
    int num = (rand() % (upper - lower + 1)) + lower;
    q->data[++q->temp.rear2] = num;
}

int empty(prod_cons* q)
{
    if(q->temp.front1>q->temp.rear1){
        return 1;
    }else{
        return 0;
    }
}

void Consume_from_Produce(prod_cons* q)
{
    if(empty(q)){
        printf("Queue empty\n");
        return;
    }
    q->temp.consume=1;
    int x=q->data[q->temp.front1];
    q->temp.front1++;
    printf("Deleted: %d\n",x);
}

void Consume_from_Consume(prod_cons* q)
{
    if(empty(q)){
        printf("Queue empty\n");
        return;
    }
    q->temp.consume=1;
    int x=q->data[q->temp.front2];
    q->temp.front2++;
    printf("Deleted: %d\n",x);
}

void Print_Producer_Consumer(prod_cons q,prod_cons p)
{
    int qflag=0;
    int pflag=0;
    if(empty(&q)){
        printf("Queue empty\n");
        qflag=1;
    }
    if(qflag==0){
        printf("Producer\n");
        for(int i=q.temp.front1;i<=q.temp.rear1;i++){
                printf("%d ",q.data[i]);
        }
    }

    if(empty(&p)){
        printf("Queue empty\n");
        pflag=1;
    }
    if(pflag==0){
        printf("\nConsumer\n");
        for(int i=p.temp.front2;i<=p.temp.rear2;i++){
                printf("%d ",p.data[i]);
        }
    }
    printf("\n");
}

void activeprod_consumer(prod_cons q,prod_cons p)
{
    if(q.temp.consume==1 && q.temp.produce==1){
        printf("Active:Producer\n");
        for(int i=q.temp.front1;i<=q.temp.rear1;i++){
                printf("%d ",q.data[i]);
        }
    }

    if(p.temp.consume==1 && p.temp.produce==1){
        printf("\nActive:Consumer\n");
        for(int i=p.temp.front2;i<=p.temp.rear2;i++){
                printf("%d ",p.data[i]);
        }
    }
    printf("\n");
}