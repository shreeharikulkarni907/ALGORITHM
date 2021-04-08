#include<stdio.h>
int main()
{
    int n,num,high;
    int flag=1;
    int low=0;
    int mid=0;
    printf("Enter the Number of elements of array\n");
    scanf("%d",&n);
    high=n-1;
    int a[n];
    printf("Enter the elements of array In Sorted Order\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element To Be searhced\n");
    scanf("%d",&num);
    while(low<high)
    {
       mid=(low+high)/(2);
       if(a[mid]==num)
       {
           flag=0;
           printf("Element Found At Position %d",mid);
       }
       if(num<a[mid])
       {
           high=mid-1;
       }
       else
       {
           low=mid+1;
       }
    }
    if(flag==1)
    {
        printf("Element Not Found");
    }
}
