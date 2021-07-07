#include<stdio.h>
#include<math.h>
int d;
int n;
int w[10];
int x[10];
void sumofsubs(int cs,int k,int r)
{
    if(k<=n)
    {
        x[k]=1;
        if(cs+w[k]==d)
        {
           for(int i=1;i<=k;i++)
           {
               if(x[i]==1)
               printf("%d\t",w[i]);
           }
           printf("\n");
        }
        else
        {
            if(cs+w[k]+w[k+1]<=d)
                sumofsubs(cs+w[k],k+1,r-w[k]);
        }
        if(cs+r-w[k]>=d && cs+w[k+1]<=d)
        {
           x[k]=0;
           sumofsubs(cs,k+1,r-w[k]);
        }

    }

}
int main()
{

    printf("Enter the Target Weight \n");
    scanf("%d",&d);
    printf("Enter The Number of weights\n");
    scanf("%d",&n);
    printf("Enter the weights\n");
    int r=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        r+=w[i];
        x[i]=0;
        //printf("\n");
    }
   // printf("%d\t\n",r);
   printf("\nSOLUTION WEIGHTS ARE\n");
    int cs=0;
    sumofsubs(cs,1,r);
}
