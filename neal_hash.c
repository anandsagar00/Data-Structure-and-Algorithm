// A Blockchain is a chain of blocks that contain data or information. Each block in a Blockchain network 
// stores some information along with the hash of its previous block. A hash is a unique mathematical code that 
// belongs to a specific block. If the block's information is modified, the hash of the block will be subjected to 
// modification.
// Neal wants to store Hash of banking transaction ID using Blockchain technology. Since Neal is new to the 
// technology, he uses odd position sum of digits if number is prime instead of hashing. Please help Neal to solve 
// the problem by using Problem Solving Framework.
// Note: Digits position starts from right to left ()
// Number: 45698
// Position: 54321
// Ex1: 
// Input: 9
// Ans: NOHASH
// Ex2:
// Input: 197
// Ans: 8
// i.e.1+7= 8 (197 is a prime number)

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    int count=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        count++;
    }
    if(count>0)
    printf("NO HASH.");
    else
    {
        int cn=n;
        int i=1;
        int sum=0;
        while(cn>0)
        {
            if(i%2==1)
            sum=sum+(cn%10);
            cn=cn/10;
            i++;
        }
        printf("HASH is %d",sum);
    }
}