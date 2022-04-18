#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    int cn=n;
    int sod=0;
    while(cn>0)
    {
        sod=sod+(cn%10);
        cn=cn/10;
    }
    if(n%sod==0)
    {
        printf("Sum of digits of number is : %d\n",sod);
    }
    else
    {
        int cn2=n;
        int i=1;
        int sum_odd=0;
        while(cn2>0)
        {
            int dig=cn2%10;
            if(dig%2==1)
            sum_odd=sum_odd+dig;
            cn2=cn2/10;
        }
        printf("Odd digit sum is : %d",sum_odd);
    }
}