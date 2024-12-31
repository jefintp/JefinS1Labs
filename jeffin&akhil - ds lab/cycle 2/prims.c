#include <stdio.h>
#include <conio.h>

void main()
{
    int n,ar[25][25],visited[25],k,e = 0,cost = 0;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

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
    }

    visited[0] = 1;
    printf("\nEdges of Minimum cost spanning tree are :\n");

    while (e < n-1) 
    {
        int min, u, v;
        for (int i = 0; i < n; i++) 
        {
            if (visited[i]) 
            {
                min = 1000;
                for (int j = 0; j < n; j++) 
                {
                    if (ar[i][j] < min && !visited[j]) 
                    {
                        min = ar[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        printf("{%d, %d} = %d\n", u, v, min);
        cost += min;
		e++;
    }
    printf("\nMinimum Cost: %d\n", cost);
}