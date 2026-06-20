#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(char **arr, int size){
    printf("The original array is: [%s,", arr[0]);
    for(int i=1; i<size; i++){
        if(i==size-1)
            printf(" %s]\n", arr[i]);
        else
            printf(" %s,", arr[i]);

    }
    int j;
    char *temp;
    for(int i=1; i<size; i++){
        for(j=i; j>0; j--){
            if(strcmp(arr[j-1],arr[j])>0){
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                }
            }
    }
    printf("The sorted array is: [%s,", arr[0]);
    for(int i=1; i<size; i++){
        if(i==size-1)
            printf(" %s]\n", arr[i]);
        else
            printf(" %s,", arr[i]);
    }
}

int main(){
    int N;
    printf("Give a number of elements for the array\n");
    scanf("%d", &N);
    printf("Please enter the words you would like to sort\n");
    char **a=malloc(N*sizeof(char*));
    for(int i=0; i<N; i++){
        char temp[100];
        scanf("%99s", temp);
        a[i]=malloc((strlen(temp)+1)*sizeof(char));
        strcpy(a[i], temp);
    }
    
    insertionSort(a, N);
    for(int i=0; i<N; i++){
        free(a[i]);
    } 
    free(a);
    return 0;
} 