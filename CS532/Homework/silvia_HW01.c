#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
-Compiling Instrucitons-

To compile use: gcc -o silvia_HW01 silvia_HW01.c

To execute use: ./silvia_HW01
*/

int sumOfDigits(int n){
    int sum=0;
    if(n<=0){
        sum=-1;
    }
    else{
        while(n>0){ //when all digits are subtracted out will stop loop
            int temp=n%10; //stores the ones digit by making it the remainder
            sum+=temp; 
            n=(n-temp)/10; //removes the ones digit by subtracting it and dividing by ten to make the tens digit the one
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
            max=arr[i]; //replaces maximum with new value if it is larger than the stored value
        }
        if(arr[i]<min){
            min=arr[i]; //replaces minimum with new value if it is smaller than the stored value
        }
    }
    diff=max-min;
    return diff;
}

int replaceEvenWithZero(int *arr, int len){
    for(int i=0; i<len; i++){
        if(arr[i]%2==0){ //if there is no remainder after dividing by 2, number is even and replaced by 0
            arr[i]=0;
        }
    }
    return *arr;
}

bool perfectSquare(int n){
    for(int i=1; i<(n+3)/2; i++){ //square numbers above four have a square root less than half their value, prevents iterating the second half
        if(i*i==n){              //1 and 4 have square roots larger than half their value, so adding 3 allows the function to work for them as well
            return true;
        }
    }
    return false;
}

int countVowels(char *s, int len){
    int sum=0;
    for(int i=0; i<len; i++){
        if(s[i]<91 && s[i]>64){ //ASCII for uppercase letters
            s[i]=s[i]+32;       //adds 32 to correlate to lowercase ASCII
        }                       //could have used string function tolower(), too late now
        int temp=s[i];
        if(temp==97 || temp==101 || temp==105 || temp==111 || temp==117){ //if ASCII of char is the same as ASCII of lowercase vowels adds 1 to total number of vowels
            sum+=1;
        } 
    }
    return sum;
}

int main(){

    printf("\n-Sum of Digits-\n");
    printf("n=%d: %d\nn=%d: %d\nn=%d: %d\nn=%d: %d\nn=%d: %d\n", 123, sumOfDigits(123), 405, sumOfDigits(405), 0, sumOfDigits(0), 7, sumOfDigits(7), -308, sumOfDigits(-308));

    printf("\n-Max Min Difference-\n");
    int arr1[]={3,7,2,9}, arr2[]={5,5,5,5,5,5}, arr3[]={-2,4,-1,6,5};
    printf("arr=[3, 7, 2, 9]: %d\n", UABMaxMinDiff(arr1,sizeof(arr1)/sizeof(arr1[0])));
    printf("arr=[5,5,5,5,5,5]: %d\n", UABMaxMinDiff(arr2,sizeof(arr2)/sizeof(arr2[0])));
    printf("arr=[-2, 4, -1, 6, 5]: %d\n", UABMaxMinDiff(arr3,sizeof(arr3)/sizeof(arr3[0])));

    printf("\n-Replace with Zero-\n");
    int zarr1[]={1,2,3,4}, zarr2[]={2,4,6}, zarr3[]={1,3,5};
    int len=sizeof(zarr1)/sizeof(zarr1[0]);
    replaceEvenWithZero(zarr1, len);
    printf("arr=[1, 2, 3, 4]: [%d,", zarr1[0]);
    for(int i=1; i<len; i++){
        if(i==len-1)
            printf(" %d]\n", zarr1[i]);
        else
            printf(" %d,", zarr1[i]);
    }
    len=sizeof(zarr2)/sizeof(zarr2[0]);
    replaceEvenWithZero(zarr2, len);
    printf("arr=[2, 4, 6]: [%d,", zarr2[0]);
    for(int i=1; i<len; i++){
        if(i==len-1)
            printf(" %d]\n", zarr2[i]);
        else
            printf(" %d,", zarr2[i]);
    }
    len=sizeof(zarr3)/sizeof(zarr3[0]);
    replaceEvenWithZero(zarr3, len);
    printf("arr=[1, 3, 5]: [%d,", zarr3[0]);
    for(int i=1; i<len; i++){
        if(i==len-1)
            printf(" %d]\n", zarr3[i]);
        else
            printf(" %d,", zarr3[i]);
    }

    printf("\n-Perfect Square-\n");
    int sqrarr[]={16,15,25,36}; //put test ints in array to iterate and save room in line
    for(int i=0; i<sizeof(sqrarr)/sizeof(sqrarr[0]); i++){
        if(perfectSquare(sqrarr[i])){
            printf("n=%d: True\n", sqrarr[i]);
        }
        else{
            printf("n=%d: False\n", sqrarr[i]);
        }
    }
    
    printf("\n-Count Vowels-\n");
    char s1[]="Hello World", s2[]="UAB CS", s3[]="Python", s4[]="aeiou";
    printf("[Hello World]: %d\n", countVowels(s1, sizeof(s1)/sizeof(s1[0])));
    printf("[UAB CS]: %d\n", countVowels(s2, sizeof(s2)/sizeof(s2[0])));
    printf("[Python]: %d\n", countVowels(s3, sizeof(s3)/sizeof(s3[0])));
    printf("[aeiou]: %d\n\n", countVowels(s4, sizeof(s4)/sizeof(s4[0])));
    
    return 0;
}
