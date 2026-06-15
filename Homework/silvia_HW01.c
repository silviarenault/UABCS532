#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int sumOfDigits(int n){
    int sum=0;
    if(n<=0){
        sum=-1;
    }
    else{
        while(n>0){
            int temp=n%10;
            sum+=temp;
            n=(n-temp)/10;
        }
    }
    return sum;
}

int UABMaxMinDiff(int *arr, int len){
    int max=arr[0];
    int min=arr[0];
    int diff;
    for(int i=1; i<len; i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    diff=max-min;
    return diff;
}

int replaceEvenWithZero(int *arr, int len){
    return 0;
}

bool perfectSquare(int n){
    for(int i=1; i<(n+3)/2; i++){
        if(i*i==n){
            return true;
        }
    }
    return false;
}

int countVowels(char *s, int len){
    int sum=0;
    for(int i=0; i<len; i++){
        if(s[i]<91 && s[i]>64){
            s[i]=s[i]+32;
        }
        int temp=s[i];
        if(temp==97 || temp==101 || temp==105 || temp==111 || temp==117){
            sum+=1;
        } 
    }
    return sum;
}

int main(){
    printf("\n-Sum of Digits-\n");
    printf("n=%d: %d\nn=%d: %d\nn=%d: %d\nn=%d: %d\nn=%d: %d\n", 123, sumOfDigits(123), 405, sumOfDigits(405), 0, sumOfDigits(0), 7, sumOfDigits(7), -308, sumOfDigits(-308));

    printf("\n-Max Min Difference-\n");
    int arr1[]={3,7,2,9};
    printf("arr=[3, 7, 2, 9]: %d\n", UABMaxMinDiff(arr1,sizeof(arr1)/sizeof(arr1[0])));
    int arr2[]={5,5,5,5,5,5};
    printf("arr=[5,5,5,5,5,5]: %d\n", UABMaxMinDiff(arr2,sizeof(arr2)/sizeof(arr2[0])));
    int arr3[]={-2,4,-1,6,5};
    printf("arr=[-2, 4, -1, 6, 5]: %d\n", UABMaxMinDiff(arr3,sizeof(arr3)/sizeof(arr3[0])));

    printf("\n-Replace with Zero-\n");
    int len;

    printf("\n-Perfect Square-\n");
    int sqrarr[]={16,15,25,36};
    for(int i=0; i<sizeof(sqrarr)/sizeof(sqrarr[0]); i++){
        if(perfectSquare(sqrarr[i])){
            printf("n=%d is a perfect square\n", sqrarr[i]);
        }
        else{
            printf("n=%d is not a perfect square\n", sqrarr[i]);
        }
    }
    
    printf("\n-Count Vowels-\n");
    char s1[]="Hello World";
    printf("[Hello World] has %d vowels\n", countVowels(s1, sizeof(s1)/sizeof(s1[0])));
    char s2[]="UAB CS";
    printf("[UAB CS] has %d vowels\n", countVowels(s2, sizeof(s2)/sizeof(s2[0])));
    char s3[]="Python";
    printf("[Python] has %d vowels\n", countVowels(s3, sizeof(s3)/sizeof(s3[0])));
    char s4[]="aeiou";
    printf("[aeiou] has %d vowels\n\n", countVowels(s4, sizeof(s4)/sizeof(s4[0])));
    
    return 0;
}