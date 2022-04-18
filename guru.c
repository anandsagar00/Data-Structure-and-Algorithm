// Suri and Guru are talented students; they always want to be unique in their class. After research, by referring 
// to some mathematics books, Suri comes with a special number. A number is a special number if the sum of 
// factorial of the digits is equal to the number. Guru wants to implement the same by using a programming language. 
// Please help Guru to solve the problem by using Problem Solving Framework.
// Ex1: 145 is a special number.
// Explanation 
// 1! + 4! + 5! 
// 1+24+120=145

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    int cn=n;
    int sum=0;
    while(cn>0)
    {
        int dig=cn%10;
        int fact=1;
        for(int i=1;i<=dig;i++)
        fact*=i;
        sum+=fact;
        cn=cn/10;
    }
    if(sum==n)
    printf("Special Number");
    else
    printf("Not a special Number.");
}