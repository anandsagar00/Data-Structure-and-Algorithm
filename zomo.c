// Online food delivery applications such as SWAG[S] and ZOMO[Z] have planned to give their 
// customers some offers, as it’s a month-end. SWAG has intended to provide no offer if the 
// ordered bill is less than 500, 10% offer if the ordered bill is more than 500, 20% offer if the 
// ordered bill is more than 1000, and 30% offer if the ordered bill is more than 1500. ZOMO 
// also has planned to give 5% offer if the ordered bill is less than 500, 10% offer if the ordered 
// bill lies in between 500 to 1200, 15% offer if the ordered bill is more than 1200, and 20% 
// offer if the ordered bill is more than 2000. Help SWAG and ZOMO to generate the bills after 
// applying the offers by applying Problem Solving Framework. 

#include<stdio.h>
int main()
{
    char ch;
    printf("Enter S for SWAG and Z for ZOMO : ");
    scanf("%c",&ch);
    if(ch=='s' || ch=='S')
    {
        float price;
        printf("Enter price : ");
        scanf("%f",&price);
        float bill=0;
        if(price<=500)
        bill=price;
        else if(price>500 && price<=1000)
        {
            bill=price-(price*0.1);
        }
        else if(price>1000 && price<=1500)
        {
            bill=price-(price*0.2);
        }
        else if(price>1500)
        bill=price-(price*0.3);
        printf("Your SWAG Bill is : Rs. %f",bill);
    }
    else if(ch=='z' ||ch=='Z')
    {
        float price;
        printf("Enter price : ");
        scanf("%f",&price);
        float bill=0;
        if(price<=500)
        bill=price-(price*0.05);
        else if(price>500 && price<=1200)
        {
            bill=price-(price*0.1);
        }
        else if(price>1200 && price<=2000)
        {
            bill=price-(price*0.15);
        }
        else if(price>2000)
        bill=price-(price*0.2);
        printf("Your SWAG Bill is : Rs. %f",bill);
    }
}
