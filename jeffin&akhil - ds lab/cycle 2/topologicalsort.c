#include <stdio.h>
#include <string.h>

int indegree(int ar[25][25], int n, int node) 
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += ar[i][node];
    return sum;
}

void main() 
{
    int n,ar[25][25],visited[25];
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter the element A[%d][%d] : ",i,j);
            scanf("%d",&ar[i][j]);
        }
    }

    int count = 0;
    while (count < n) {
        for (int i = 0; i < n; i++) 
        {
            if (indegree(ar, n, i) == 0 && visited[i]==0) 
            {
                printf("%d \n", i);
                visited[i] = 1;

                for (int j = 0; j < n; j++) 
                    ar[i][j] = 0;
                break;
            }
        }
        count++;
    }
}
