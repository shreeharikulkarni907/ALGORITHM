#include<stdio.h>
#include<math.h>
#include<time.h>
void swap(int *x,int *y);
void sort(int a[],int n);
int main()
{
    clock_t start,end;

    int b[]={0,50,100,500,1000,5000,10000,15000,20000,25000,30000,35000,40000};
   // printf("%d",b[0]);
   for(int i=0;i<13;i++)
   {
       int a[b[i]];
       for(int j=0;j<b[i];j++)
       {
           a[j]=rand();
       }
       start=clock();
       sort(a,b[i]);
       end=clock();
       printf("Time Taken For %d = %f\n",b[i],((double)((end-start)/(CLOCKS_PER_SEC))));
   }

}
void swap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
void sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
    printf("SORTED ORDER IS \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
