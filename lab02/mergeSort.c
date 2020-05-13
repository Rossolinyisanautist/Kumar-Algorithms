#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void merge(int* arr, int low, int mid, int high) 
{ 
    int i, j, k; 
    int sz_a = mid - low + 1; 
    int sz_b =  high - mid; 
  
    int a[sz_a], b[sz_b]; 
  
    for (i = 0; i < sz_a; i++) {
        a[i] = arr[low + i]; 
    }
    for (j = 0; j < sz_b; j++) {
        b[j] = arr[mid + j + 1]; 
    }

    i = j = 0; 
    k = low; 
    while (i < sz_a && j < sz_b) 
    { 
        if (a[i] <= b[j]) 
        { 
            arr[k++] = a[i++]; 
        } 
        else
        { 
            arr[k++] = b[j++]; 
        } 
    } 

    while (i < sz_a) 
    { 
        arr[k++] = a[i++]; 
    } 
  
    while (j < sz_b) 
    { 
        arr[k++] = b[j++]; 
    } 

} 

void mergeSort(int* arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int mid = low + (high - low) / 2; 

        mergeSort(arr, low, mid); 
        mergeSort(arr, mid + 1, high); 
        merge(arr, low, mid, high); 
    } 
} 

int main(int argc, char** argv) {

    int sz = -1;
    printf("Enter size of array:\n");
    scanf("%d", &sz);
    int arr[sz]; 

    srand(time(NULL));  
    for (int i = 0; i <= sz; ++i)
    {
    	arr[i] = rand() % (sz * 20);
    }

    clock_t begin = clock();
    mergeSort(arr, 0, sz - 1); 
    clock_t end = clock();
    
    printf("Total time: %f seconds\n", ((double) (end - begin)) / CLOCKS_PER_SEC); 
    return 0; 
} 
