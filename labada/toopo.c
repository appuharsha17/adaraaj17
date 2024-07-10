#include<stdio.h>
int a[10][10],n,indegree[10];
void find_indegree()
{
    int j,i,sum;
    for(j=0;j<n;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+a[i][j];
            indegree[j]=sum;
        }
    }
}
void topology()
{
    int i,u,v,s[10],t[10],top=-1,k=0;
    find_indegree();
    for(i=0;i<n;i++)
    {
        if(indegree[i]==0)
            s[++top]=i;
    }
    while(top!= -1)
    {
        u=s[top--];
        t[k++]=u;
        for(v=0;v<=n;v++)
        {
            if(a[u][v]==1)
            {
                indegree[v]--;
                if(indegree[v]==0)
                    s[++top]=v;
            }
        }
    }
    printf("the topological sequence: \n");
    for(i=0;i<n;i++)
        printf("%d ",t[i]);
}
void main()
{
    int i,j;
    printf("Enter the number of jobs: \n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    topology();
}