#include<stdio.h>
#include<math.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int cap,n;
    printf("Enter the knapsack capacity\n");
    scanf("%d",&cap);
    printf("Enter the Number of instances\n");
    scanf("%d",&n);
    int w[n+1];
    int v[n+1];
    printf("Enter the weight of the Instances\n");
    for(int i=1;i<=n;i++)
    {
        printf("Enter the weight of the instance %d\n",i);
        scanf("%d",&w[i]);
    }
    printf("Enter the Value of the instances\n");
    for(int i=1;i<=n;i++)
    {
        printf("Enter the value of the instance %d\n",i);
        scanf("%d",&v[i]);
    }
    int a[n+1][cap+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            a[i][j]=0;
        }
        printf("\n");
    }
    int optimal=0;
    int ins=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cap;j++)
        {
            if(j-w[i]>=0)
            {
                a[i][j]=max(a[i-1][j],v[i]+a[i-1][j-w[i]]);
                if(a[i][j]>optimal)
                {
                    optimal=a[i][j];
                    ins=i;
                }
            }
            else
            {
                a[i][j]=a[i-1][j];
            }
        }
    }
    printf("FINAL SOLUTION MATRIX IS\n");
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("Optimal Solution Is %d\n",optimal);
    printf("Optimal solution includes following instances\n");
    printf("%d\t",ins);
    v[ins]=0;
    int wl=cap-w[ins];
    int previns=ins;
    while(wl>=0)
    {
        optimal=0;
      for(int i=1;i<=n;i++)
       {

          if(v[i]!=0)
          {
             if(a[i][wl]>optimal)
             {
                 optimal=a[i][wl];
                 ins=i;
             }
          }

       }
       printf("%d\t",ins);
       v[ins]=0;
       wl=wl-w[ins];

    }

}
