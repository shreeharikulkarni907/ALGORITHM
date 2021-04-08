#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int num;
    int flag=1;
    int n;
    printf("Enter the Number of elements of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element To Be searhced\n");
    scanf("%d",&num);
    for(int i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            flag=0;
            printf("First Occurance of the element is found at position %d" + i);
            break;
        }
    }
    if(flag==1)
    {
        printf("Element Not Found\n");
    }

}
