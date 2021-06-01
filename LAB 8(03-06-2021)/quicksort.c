#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int start,int end)
{
    int pivot=a[end];
    int pindex=start;
    for(int i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            swap(&a[pindex],&a[i]);
            pindex++;
        }
    }
    swap(&a[pindex],&a[end]);
    return pindex;
}
void quicksort(int a[],int start,int end)
{
    //printf("HEloo\n");
    if(start<end)
    {
        int pi=partition(a,start,end);
        quicksort(a,start,pi-1);
        quicksort(a,pi+1,end);
    }
}
int main()
{
    int n,option;
    printf("Enter the number of the elements the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter The Elements of the array\n");
    printf("1:Input From User\n");
    printf("2: Using Random Fucntion\n");
    printf("Enter Your Option\n");
    scanf("%d",&option);
    printf("\n");
    switch(option)
    {
    case 1:
        printf("Enter The Elements\n");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        break;
    case 2:
        printf("Elements Taken In Random Order\n");
        for(int i=0;i<n;i++)
        {
            a[i]=rand();
        }
        break;
    }
    clock_t t;
    t=clock();
    quicksort(a,0,n-1);
    t=clock() - t;
    printf("Elements of the array are\n");
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n Time taken for %d = %f seconds  \n",n,time_taken);
}



