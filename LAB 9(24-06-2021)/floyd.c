#include<stdio.h>
#include<math.h>

int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int a[n+1][n+1];
    printf("Enter the Distance matrix\n");
    printf("GIVE THE DISTANC AS 9999 If there is no edge\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
            }
        }
    }
    printf("ALL PAIR SHORTEST PATH DISTANCE MATRIX IS\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

