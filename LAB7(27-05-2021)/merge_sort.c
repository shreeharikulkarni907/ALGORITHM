#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void mergesort(int left[],int right[],int a[],int nl,int nr);
void split(int n,int a[])
{

    int mid,i,j;
    if(n<2)
        return;
    mid=(n)/2;
    int left[mid];
    int right[n-mid];
    for(i=0;i<mid;i++)
    {
        left[i]=a[i];
    }
    for(j=mid;j<n;j++)
    {
        right[j-mid]=a[j];
    }
    split((sizeof(left))/(sizeof(int)),left);
    split((sizeof(right))/(sizeof(int)),right);
    mergesort(left,right,a,(int)((sizeof(left))/sizeof(int)),(int)((sizeof(right))/sizeof(int)));
}
void mergesort(int left[],int right[],int a[],int nl,int nr)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<nl&&j<nr)
    {
        if(left[i]<right[j])
        {
            a[k]=left[i];
            i++;
        }
        else
        {
            a[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        a[k]=right[j];
        j++;
        k++;
    }
}
int main()
{
    clock_t t;
    int n;
    printf("Enter The Size Of The Array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter The Elements of the array\n");
    for(int i=0;i<n;i++)
    {
        //scanf("%d",&a[i]);
        a[i]=rand();
    }
    t=clock();
    split(n,a);
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("Time Taken =%f\n",time_taken);
    printf("Final Sorted Order Is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

}
