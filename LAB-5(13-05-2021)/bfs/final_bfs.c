#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int q[100];
int visited[100];
int adj[20][20];
int n;
void enqueue(int v);
int dequeue();
int front=-1;
int rear=-1;
void enqueue(int v)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
    }
    if(rear==n-1)
    {
        printf("Queue Full\n");
        return;
    }
    q[rear]=v;
    rear++;
}
int dequeue()
{
    int val;
    if(front==-1 || front>rear)
    {
        //printf("Queue Underflow\n");
        return -1;
    }
    val=q[front];
    if(front==rear || front>rear)
    {
        front=-1;
        rear=-1;
    }
    front++;
    return val;
}
void bfs(int v)
{
    for(int i=0;i<n;i++)
    {
        if(adj[v][i]==1 && visited[i]==0)
        {
            enqueue(i);
            printf("%d\t",i);
            visited[i]=1;
        }
    }
    int val=dequeue();

    if(val!=-1)
    {
        bfs(val);
    }
    else
    {
        return;
    }
}
int main()
{
    int flag=1;
    int v;
    printf("Enter the Number of the vertex\n");
    scanf("%d",&n);
    printf("Enter the Entries Of The Adjacent Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the Starting Vertex\n");
    scanf("%d",&v);
    printf("BREADTH ORDER TRAVERSAL FOR FOREST 1 IS\n");
    printf("%d\t",v);
    visited[v]=1;
    bfs(v);

    printf("\nSBREADTH ORDER TRAVERSAL FOR FOREST 2 IF IT EXISTS\n");
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            flag=0;
            printf("%d\t",i);
            visited[i]=1;
            bfs(i);
            break;
        }
    }
    if(flag==1)
    {
        printf("\nGRAPH IS CONNECTED\n");
    }


}
