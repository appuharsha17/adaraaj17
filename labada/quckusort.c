#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Exchange(int *p,int *q)
{
    int temp= *p;
    *p=*q;
    *q=temp;
}
void quickSort(int a[],int low,int high)
{
    int i,j,k,key;
    if(low>=high)
        return;
    key=low;
    i=low+1;
    j=high;
    while(i<=j)
    {
        while(a[i]<=a[key])
        i++;
        while(a[j]>a[key])
        j--;
        if(i<j)
        Exchange(&a[i],&a[j]);
    }
    Exchange(&a[j],&a[key]);
    quickSort(a,low,j-1);
    quickSort(a,j+1,high);
}
int main()
{
    int n,a[20000],k;
    clock_t st,et;
    double ts;
    printf("Enter how many numbers: ");
    scanf("%d",&n);
    printf("\nThe random numbers are: \n");
    for(k=0;k<n;k++)
    {
        a[k]=rand();
        printf("%d\t",a[k]);
    }
    st=clock();
    quickSort(a,0,n-1);
    et=clock();
    ts=(double)(et-st)/CLOCKS_PER_SEC;
    printf("\nThe sortde numbers are: \n");
    for(k=0;k<n;k++)
    {
        printf("%d\t",a[k]);
    }
    printf("\nThe time taken is %e ", ts);
    return 0;

}