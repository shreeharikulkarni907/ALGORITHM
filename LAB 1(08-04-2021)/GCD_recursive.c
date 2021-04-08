#include<stdio.h>
int gcd(int x,int y);
int main()
{
    int x,y;
    printf("Enter The First Number\n");
    scanf("%d",&x);
    printf("Enter the Second Number\n");
    scanf("%d",&y);
    int ans=gcd(x,y);
    printf("GCD OF %d AND %d is %d",x,y,ans);

}
int gcd(int x,int y)
{
    int rem;
    int temp;
    if(x>y)
    {
        rem=x%y;
    }
    else
    {
        temp=y;
        y=x;
        x=temp;
        rem=x%y;
    }
    if(rem==0)
    {
        return y;
    }
    else
    {
        return gcd(y,rem);
    }
}
