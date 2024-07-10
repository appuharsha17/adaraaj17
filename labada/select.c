#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int array[],int size)
{
    int i,j,min,temp;
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {
            if(array[j]<array[min])
            min=j;
        }
        temp=array[min];
        array[min]=array[i];
        array[i]=temp;
    }
}
int main()
{
    int n,a[50000],k;
    clock_t st,et;
    double ts;
    printf("Enter how many numbers: ");
    scanf("%d",&n);
    printf("The random numbers are\n");
    for(k=0;k<n;k++)
    {
        a[k]=rand();
        printf("%d\t",a[k]);
    }
    st=clock();
    selectionSort(a,n);
    et=clock();
    ts=(double)(et-st)/CLOCKS_PER_SEC;
    printf("The sorted numbers are:\n");
    for(k=0;k<n;k++)
    {
        printf("%d\t",a[k]);
    }
    printf("\nThe time taken is %e ",ts);
    return 0;
}