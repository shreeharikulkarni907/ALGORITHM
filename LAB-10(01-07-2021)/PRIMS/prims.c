#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 6
int minKey(int key[],bool mstset[])
{
    int min,minIndex;
    min=INT_MAX;
    for(int i=0;i<V;i++)
    {
        if(mstset[i]==false && key[i]<min)
        {
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void printmst(int parent[],int graph[V][V])
{
    int sum=0;
    printf("EDGE\tWEIGHT\n");
    for(int i=1;i<V;i++)
    {
        printf("%d-%d\t%d\n",parent[i],i,graph[i][parent[i]]);
        sum=sum+graph[i][parent[i]];
    }
    printf("Total Minimal Cost Is%d\n",sum);

}
void primst(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstset[V];
    for(int i=0;i<V;i++)
    {
        //parent[i]=0;
        key[i]=INT_MAX;
        mstset[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<V-1;count++)
    {
        int u=minKey(key,mstset);
        mstset[u]=true;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && mstset[v]==false && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    printmst(parent,graph);
}
int main()
{
    int graph[V][V];
    printf("Enter the Distance Matrix\n");
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    primst(graph);
}

