#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFSIZE 4096

int main(int argc, char *argv[]){
    int f1,f2;
    long int n;
    char buf[BUFFSIZE];

    if(argc!=3){
        printf("Usage: %s <destination_filename> <source_filename>\n", argv[0]);
        exit (-1);
    }
    f1=open(argv[1], O_WRONLY | O_APPEND, 0700);
    f2=open(argv[2], O_RDONLY);
    if(f1==-1 || f2==-1){
        if(f1==-1){
            printf("Error opening %s\n", argv[1]); 
        }
        if(f2==-1){
            printf("Error opening %s\n", argv[2]);
        }
        exit (-1);
    }
    if(strcmp(argv[1],argv[2])==0){
        printf("Cannot concatenate a file to itself\n");
        exit (-1);
    }
    while((n=read(f2, buf, BUFFSIZE))>0){
        if(write(f1, buf, n)!=n){
            printf("Error writing to first file\n");
        }
    }
    close(f1);
    close(f2);
    return 0;
}