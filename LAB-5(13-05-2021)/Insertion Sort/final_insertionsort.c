#include<stdio.h>
#include<time.h>
void sort(int a[],int n);
int main()
{
    clock_t t;
    int n;
    printf("\nEnter the Number Of Elements Of The Array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    t=clock();
    sort(a,n);
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("Time Taken =%f\n",time_taken);

    printf("Final Sorted Order Is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

}
void sort(int a[] ,int n)
{
    int v,j;
    for(int i=1;i<=n-1;i++)
    {
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=v;

    }
}
