#include<stdio.h>
#include<math.h>
#include<time.h>
#include <unistd.h>
void swap(int *x,int *y);
void sort(int a[],int n);
int main()
{
    clock_t start,end;

   int b[]={5000};
   double c[10];
   int m=0;
   for(int i=0;i<1;i++)
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
       //c[m]=((double)((end-start)/(CLOCKS_PER_SEC)));
       m++;
   }
   for(int i=0;i<10;i++)
   {
       printf("%d=%f\n",b[i],c[i]);
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
    printf("Final Sorted Array Is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    //printf("\n*****SORTED ARRAY******\n");
    printf("\n");
   // sleep(10);
}
