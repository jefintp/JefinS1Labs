#include<stdio.h>
#include<conio.h>

int ar[25][25],visited[25],parent[25];

int find(int i)
{
    if (parent[i]==i)
		return i;

	int root = find(parent[i]);
	parent[i] = root;
	return root;
}

int uni(int u,int v)
{
    u = find(u);
	v = find(v);

    if(u!=v)
    {
        parent[v]=u;
        return 1;
    }
    return 0;
}

void main()
{
    int n,k,u,v;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter the element A[%d][%d] : ",i,j);
            scanf("%d",&k);
            if(k==0)
                k=1000;
            ar[i][j]=k;
        }
        parent[i]=i;
    }

    int mst[n][n],e=0,cost=0,min=1000,un;
    printf("\nEdges of Minimum cost spanning tree are :\n");
    while(e < n-1)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(ar[i][j]<min)
                {
                    min=ar[i][j];
                    u=i;
                    v=j;
                }
        un=uni(u,v);
        if(un==1)
        {
            printf("edge %d - (%d,%d) = %d\n",e+1,u,v,min);
            cost+=min;
            e++;
        }
        ar[u][v]=ar[v][u]=1000;
        min=1000;
    }
    printf("\nMinimum cost = %d",cost);
}