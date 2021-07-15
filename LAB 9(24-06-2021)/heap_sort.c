#include<stdio.h>
#include<math.h>
void swap(int *x,int *y)
{
   int temp=*x;
   *x=*y;
   *y=temp;
}
void heapify(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        int k=i;
        int v=a[k];
        int heap=0;
        while(!heap && 2*k<=n)
        {
            int j=2*k;
            if(j<n)
            {
                if(a[j]<a[j+1])
                {
                    j=j+1;
                }
            }
            if(v>a[j])
                heap=1;
            else
            {
                a[k]=a[j];
                k=j;
            }
            a[k]=v;
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of elements of the array\n");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter the elements of the array\n");
    for(int i=1;i<(n+1);i++)
    {
        scanf("%d",&a[i]);
    }
    heapify(a,n);

    printf("\n");
    for(int i=n;i>=1;i--)
    {
        swap(&a[1],&a[i]);
        heapify(a,i-1);
    }
    printf("AFTER SORTINFG THE ARRAY IS\n");
    for(int i=1;i<n+1;i++)
        printf("%d\t",a[i]);


}
