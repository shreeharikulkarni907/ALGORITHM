#include<stdio.h>
#include<math.h>
int n;
int c[10][10];
void kruskal()
{
    int i,j,a,b,u,v,min;
    int mincost=0;
    int ne=0;
    int parent[n+1];
    for(int i=1;i<=n;i++)
    {
        parent[i]=0;
    }
    while(ne!=n-1)
    {
        min=9999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(c[i][j]<min)
                {
                    min=c[i][j];
                    u=a=i;
                    v=b=j;
                }
            }
        }
        while(parent[u]!=0)
        {
            u=parent[u];
        }
        while(parent[v]!=0)
        {
            v=parent[v];
        }
        if(v!=u)
        {
            printf("%d-%d\t%d\n",u,v,min);
            parent[v]=u;
            ne++;
            mincost=mincost+min;
        }
        c[a][b]=c[b][a]=9999;
    }
    printf("\n MIN COST=%d\n",mincost);

}
int main()
{
    printf("Enter the Number of vertices\n");
    scanf("%d",&n);
    printf("Enter the Cost Matrix\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    printf("EDGE\tWeight\n");
    kruskal();
}
