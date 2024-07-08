# include <stdio.h> 
#include<stdlib.h>
# include <time.h> 
void Exch(int *p, int *q) 
{ 
    int temp = *p; 
    *p = *q; 
    *q = temp; 
} 
void QuickSort(int a[], int low, int high) 
{ 
    int i, j, key, k;  
    if(low>=high) 
        return; 
    key=low; 
    i=low+1; 
    j=high;  
    while(i<=j) 
    { 
        while ( a[i] <= a[key] ) 
        i++;  
        while ( a[j] > a[key] )  
        j--; 
        if(i<j)  
        Exch(&a[i], &a[j]); 
    } 
    Exch(&a[j], &a[key]);  
    QuickSort(a, low, j-1);  
    QuickSort(a, j+1, high); 
} 
int main() {
    int n, a[200000], k;
    clock_t st, et;
    double ts;

    printf("\nEnter how many numbers: ");
    scanf("%d", &n);

    printf("\nThe random numbers are:\n");
    for (k = 0; k < n; k++) {
        a[k] = rand();
        printf("%d\t", a[k]);
    }

    st = clock();
    QuickSort(a,0,n-1);
    et = clock();

    ts = (double)(et - st) / CLOCKS_PER_SEC;

    printf("\nSorted numbers are:\n");
    for (k = 0; k < n; k++) {
        printf("%d\t", a[k]);
    }

    printf("\nThe time taken is %e seconds\n", ts);

    return 0;
}
