#include <stdio.h>
#include <string.h>
//if the array of the first string you concatonate is too small for the added strings it will cut off, allocate more space than anticipated

int insertionSort(char *arr, int N){
    char *arr=(char*)malloc(N*sizeof(char));
    printf("The original array is: [%d,", arr[0]);
    for(i=1; i<N; i++){
        if(i==N-1)
            printf(" %c]\n", arr[i]);
        else
            printf(" %c,", arr[i]);

    }

    printf("%d\n", strcmp(arr[0],arr[1]));
    printf("%d\n", strcmp(arr[1],arr[0]));
   /* int j, temp;
    for(i=1; i<N; i++){
        for(j=i; j>0; j--){
            if(arr[j-1]>arr[j]){
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                }
            }
    } 
    printf("The sorted array is: [%d,", arr[0]);
    for(i=1; i<N; i++){
        if(i==N-1)
            printf(" %d]\n", arr[i]);
        else
            printf(" %d,", arr[i]);
    } */
    free();
    return 0;
}

int main(int N){
    printf("Give a number of elements for the array\n");
    scanf("%d", &N);
    char arr[N];
    int i;
    printf("Give %d integers to add to the array:\n", N);
    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, N);
    return 0;
}