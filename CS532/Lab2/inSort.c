#include <stdio.h>

int insertionSort(int N){
    int arr[N];
    int i;
    printf("Give %d integers to add to the array:\n", N);
    for(i=0; i<N; i++)
        scanf("%d", &arr[i]);
    printf("The original array is: [%d,", arr[0]);
    for(i=1; i<N; i++)
        if(i==N-1)
            printf(" %d]", arr[i]);
        else
            printf(" %d,", arr[i]);
    return 0;
}

int main(int N){
    printf("Give a number of elements for the array\n");
    scanf("%d", &N);
    insertionSort(N);
    return 0;
}