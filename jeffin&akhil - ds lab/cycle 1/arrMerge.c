#include<stdio.h>
#include<conio.h>
void main()
{
    int arr1[10],arr2[10],arr3[20],n1,n2,n3,i;
    printf("Enter the size of the first array  : ");
    scanf("%d",&n1);
    printf("Enter the elements for first array  :\n");
    for(i=0;i<n1;i++)
        scanf("%d",&arr1[i]);
    printf("Enter the size of the second array  : ");
    scanf("%d",&n2);
    printf("Enter the elements for second array  :\n");
    for(i=0;i<n2;i++)
        scanf("%d",&arr2[i]);
    printf("\nFirst array is :\n");
    for(i=0;i<n1;i++)
        printf("%d\t",arr1[i]);
    printf("\nSecond array is :\n");
    for(i=0;i<n2;i++)
        printf("%d\t",arr2[i]);
    n3=n1+n2;
    for(i=0;i<n3;i++)
    {
        if(i<n1)
            arr3[i]=arr1[i];
        else
            arr3[i]=arr2[i-n1];
    }
    printf("\nMerged array is :\n");
    for(i=0;i<n3;i++)
        printf("%d\t",arr3[i]);
        
}