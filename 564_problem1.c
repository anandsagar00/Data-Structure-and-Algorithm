#include <stdio.h>
#include <stdlib.h>

int change_count = 0;
struct advertisment
{
    char message_sent[100];
    int time[2];
};
typedef struct advertisment ADV;

struct stack
{
    int top;
    int active;
    ADV items[6];
} S1, S2;

typedef struct stack STACK;

STACK createStack()
{
    STACK st;
    st.top = -1;
    st.active = 0;
    return st;
}

int isEmpty(STACK stack)
{
    if (S1.top == -1)
    {
        S1.active = 0;
        S2.active = 1;
    }
    else
    {
        S1.active = 1;
        S2.active = 0;
    }
    return stack.top == -1;
}

STACK push(STACK stack, ADV item)
{
    stack.items[++stack.top] = item;
    return stack;
}

STACK pop(STACK stack)
{
    S2 = push(S2, stack.items[stack.top]);
    stack.top--;
    return stack;
}

int main()
{
    int choice;
    S1 = createStack();
    S2 = createStack();
    ADV items[6] = {
        [0].message_sent = "Have Your Snacks at nearest hotels",
        [0].time[0] = 8,
        [0].time[1] = 9,
        [1].message_sent = "Have a cup of Coffee, To start your day",
        [1].time[0] = 9,
        [1].time[1] = 10,
        [2].message_sent = "Shop for your Newborn angels",
        [2].time[0] = 10,
        [2].time[1] = 11,
        [3].message_sent = "Shop until you are statisfied, Heavy diwali discount",
        [3].time[0] = 11,
        [3].time[1] = 12,
        [4].message_sent = "Watch a movie to make your day",
        [4].time[0] = 12,
        [4].time[1] = 1,
        [5].message_sent = "Hungry, try out our exotic lunch menu",
        [5].time[0] = 1,
        [5].time[1] = 2,
    };
    S1 = push(S1, items[5]);
    S1 = push(S1, items[4]);
    S1 = push(S1, items[3]);
    S1 = push(S1, items[2]);
    S1 = push(S1, items[1]);
    S1 = push(S1, items[0]);
    S1.active = 1;

    while (1)
    {
        if (change_count >= 5)
            isEmpty(S1);
        printf("------------------Message------------------\n");
        printf("1.Message Being Brodcasted                 \n");
        printf("2.Update Time                              \n");
        printf("3.Print Message Left Over                  \n");
        printf("4.Print All Message                        \n");
        printf("5.Exit                                     \n");
        printf("-------------------------------------------\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (S1.active == 1)
                printf("Current Message : \n%s\n", S1.items[S1.top].message_sent);
            else
                printf("Current Message : \n%s\n", S2.items[S2.top].message_sent);
            break;

        case 2:
            if (S1.active == 1)
            {
                S1 = pop(S1);
                printf("Time Updated!!!!!\nCurrent Message : \n%s\n", S1.items[S1.top].message_sent);
            }
            else
            {
                S2 = pop(S2);
                printf("Time Updated!!!!!\nCurrent Message : \n%s\n", S2.items[S2.top].message_sent);
            }
            break;

        case 3:
            if (S1.active == 1)
            {
                printf("Remaining Messages : \n\n");
                for (int i = S1.top; i >= 0; i--)
                    printf("%d. %s\n", S1.top - i + 1, S1.items[i].message_sent);
            }
            else
            {
                printf("Remaining Messages : \n\n");
                for (int i = S2.top; i >= 0; i--)
                    printf("%d. %s\n", S2.top - i + 1, S2.items[i].message_sent);
            }
            break;

        case 4:
            printf("\nRemaining Messages in Stack1 : \n\n");
            for (int i = S1.top; i >= 0; i--)
                printf("%d. %s\n", S1.top - i + 1, S1.items[i].message_sent);
            printf("\n\nRemaining Messages in Stack2 : \n\n");
            for (int j = S2.top; j >= 0; j--)
                printf("%d. %s\n", S2.top - j + 1, S2.items[j].message_sent);
            break;

        case 5:
            exit(0);

        default:
            printf("Wrong Choice Enter Again...\n");
            break;
        }
    }
    return 0;
}