#include <stdio.h> 
#include<time.h> 
#include<stdlib.h>
void selectionSort(int array[], int size)  
{ 
    int i,j,min,temp; 
    for (i = 0; i < size - 1; i++)  
    { 
        min = i; 
        for (j = i + 1; j < size; j++)  
        { 
            if (array[j] < array[min]) 
            min = j; 
        } 
        temp = array[min]; 
        array[min] = array[j]; 
        array[j]= temp; 
    } 
} 
int main()  
{ 
int n, a[2000],k;  
clock_t st,et;  
double ts;  
printf("\n Enter How many Numbers:");  
scanf("%d", &n); 
printf("\nThe Random Numbers are:\n");  
for(k=0; k<=n; k++) 
{ 
    a[k]=rand();  
    printf("%d\t", a[k]); 
} 
st=clock();  
selectionSort(a, n); 
et=clock();  
ts=(double)(et-st)/CLOCKS_PER_SEC; 
printf("\n Sorted Numbers are : \n ");  
for(k=0; k<=n; k++) 
{ 
    printf("%d\t", a[k]);  
} 
printf("\nThe time taken is %e",ts);  
} 