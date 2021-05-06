#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
void toh(char src,char dest,char sp,int n);
int main()
{
    clock_t start,end;
    int a[]={3};
    double b[10];
    for(int i=0;i<1;i++)
    {
        start=clock();
        printf("\n *****For N=%d******\n",a[i]);
        toh('A','C','B',a[i]);
        end=clock();
        b[i]=((float)((end-start)/(CLOCKS_PER_SEC)));
    }
    for(int i=0;i<1;i++)
    {
        printf("\nTIME TAKEN FOR %d = %f\n",(a[i]),b[i]);
        printf("No Of Steps Taken is %f\n",(pow(2,a[i])-1));

    }
}
void toh(char src,char dest,char sp,int n)
{

    if(n==1)
    {
        printf("Move From %c to %c\n",src,dest);
        return;
    }
    else
    {
        toh(src,sp,dest,n-1);
        toh(src,dest,sp,1);
        toh(sp,dest,src,n-1);
    }
}
