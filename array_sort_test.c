#include "push_swap.h"
#include <stdio.h>

void printIntList(int *arr, int size) {
    for (int i = 0; i < size ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
	int arr[] = {5, 8, 3, 1, 7, 2};
	printIntList(arr, 6);

	array_sort(arr, 6);
	printIntList(arr, 6);
}