#include<stdio.h>
int main()
{
    char ch;
    printf("Enter U for Urban and R for Rural : ");
    scanf("%c",&ch);
    if(ch=='R' || ch=='r')
    {
        int depth;
        printf("Enter depth in feet : ");
        scanf("%d",&depth);
        int price=0;
            if(depth>=50)
            {
             price=price+(50*40);
             depth=depth-50;
            }
            if(depth>=100)
            {
             price=price+(100*50);
             depth=depth-100;
            }
            price=price+(depth*60);
        printf("Your total cost is : Rs. %d",price);
    }
    else if(ch=='U'||ch=='u')
    {
        int depth;
        printf("Enter depth in feet : ");
        scanf("%d",&depth);
        int price=0;
            if(depth>=50)
            {
             price=price+(50*60);
             depth=depth-50;
            }
            if(depth>=100)
            {
             price=price+(100*70);
             depth=depth-100;
            }
            price=price+(depth*80);
        printf("Your total cost is : Rs. %d",price);
    }
    else
    printf("Wrong Choice.");

}