#include<stdio.h>
#include<stdlib.h>
int a,b,u,v,i,j,k,n,min,ne=1;
int mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void main()
{
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the adjacecncy matrix: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    printf("The edge of minimum spanning tree is:\n");
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("\n edge %d (%d %d)=%d",ne++,a,b,min);
            mincost=mincost+min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("The minimum cost is %d ",mincost);
}
int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}