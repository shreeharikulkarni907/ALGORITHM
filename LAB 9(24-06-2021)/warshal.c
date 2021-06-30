#include<stdio.h>
#include<math.h>


int main()
{
    int n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int a[n+1][n+1];
    printf("Enter the adjacency matrix\n");
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
                if(a[i][j]==1)
                {
                    a[i][j]=1;
                }
                if(a[i][k]==1 && a[k][j]==1)
                {
                    a[i][j]=1;
                }
            }
        }
    }
    printf("TRANSITIVE CLOSURE IS\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
