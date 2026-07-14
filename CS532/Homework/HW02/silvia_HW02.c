#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int SCom=0;
int sCom=0;
int sSize=0;        //command line global variables used 
int fCom=0;         //in various functions to indicate
char fStr[1000];    //if command was given
int fDep=0;
int tCom=0;
char tType=' ';

/*
Function pointers. Needed to check which of the
commands were chosen and if all the corresponding
information was written with them.
*/

//checks that -s was chosen as well as a maximum file size
int sFun(char *name, struct stat stts, int depth){
    if(sCom==0){
        return 1;  
    }
    if(stts.st_size<=sSize){
        return 1;
    }
    return 0;
}

//checks that -f was chosen and compares strings 
//of the given substring to the file titles in the 
//heirarchy within the specified depth. Uses strncmp() 
// to specify the size of the string to compare rather 
// than an exact match.
int fFun(char *name, struct stat stts, int depth){
    if(fCom==0){
        return 1;
    }
    int nmLen=strlen(name);
    int ogLen=strlen(fStr);
    int j=0;
    for(int i=0; i<=nmLen-ogLen;i++){
        if(strncmp(name+i,fStr,ogLen)==0){
            j=1;
            break;
        }
    }
    if(j && depth <= fDep){
        return 1;
    }
    return 0;
}

//checks if -t was chosen and uses a switch command
//to determine if we should be looking for files
//or directories
int tFile(char *name, struct stat stts, int depth){
    if(tCom==0){
        return 1;
    }
    switch(tType){
        case 'f':
            if(S_ISREG(stts.st_mode)){
                return 1;
            }
            return 0;
        case 'd':
            if (S_ISDIR(stts.st_mode)){
                return 1;
            }
            return 0;
        default:
            return 0;
    }
}

//array that holds all function pointers
int (*info[3])(char*, struct stat, int)={sFun,fFun,tFile};

//allows commands to be given in any order. All
//pointer functions always return true even if the
//command isn't called to ensure the command is not
//just in a different place in the command
int allarg(char *name, struct stat stts, int depth){
    for(int i=0; i<3; i++){
        if(info[i](name, stts, depth)==0){
            return 0;
        }
    }
    return 1;
}

//creates 5 spaces of indent for every step a file
//is away from the root directory
void indnt(int depth){
    int i;
    for(i=0; i<depth;i++){
        printf("     ");
    }
}

//Prints all files in heirarchy 
void prnt(char *flnm, struct stat stts, int depth){
    indnt(depth);
    if(SCom==0){
        printf("%s\n", flnm);
        return; //stop printing line and go back to who called you
    }

    //records info associated with -S, including
    //file size, permissions, and last accessed
    int flsize;
    if(S_ISDIR(stts.st_mode)){
        flsize=0;
    }
    else{
        flsize=(int)stts.st_size;
    }
    char prm[11]; //d|l plus the nine permission characters plus null
    if(S_ISDIR(stts.st_mode)){
        prm[0]='d';
    }
    else if(S_ISLNK(stts.st_mode)){
        prm[0]='l';
    }
    else{
        prm[0]='-';
    }

    /*
    permissions are given in the 9 letter sequence seen in array flg, so array cmod contains
    all system macros associated with permissions in struct stat. If a permission is given
    the system macro can be attributed by calling the same location in cmod as in flg
    */
    char flg[9]={'r','w','x','r','w','x','r','w','x'};
    int cmod[9]={S_IRUSR,S_IWUSR,S_IXUSR,S_IRGRP,S_IWGRP,S_IXGRP,S_IROTH,S_IWOTH,S_IXOTH};
    for(int i=0;i<9;i++){
        if(stts.st_mode & cmod[i]){
            prm[i+1]=flg[i];
        }
        else{
            prm[i+1]='-';
        }
    }
    prm[10]='\0';
    char tmstr[100];
    struct tm *tm=localtime(&stts.st_atime);
    strftime(tmstr, sizeof(tmstr),"%b %d %H:%M:%S %Y",tm);
    printf("%s (%d,%s,%s)\n",flnm,flsize,prm,tmstr);
}


void traverse(char *directory, int dirDep){
    struct dirent *dirent; 
    DIR *parentDir; 

    parentDir = opendir (directory); 
    if (parentDir == NULL) { 
        printf ("Error opening directory '%s'\n", directory); 
        return;
    } 
    while((dirent = readdir(parentDir)) != NULL){
        if(strcmp((*dirent).d_name, ".")==0 || strcmp((*dirent).d_name, "..")==0){
            continue;
        }
        char pth[500];
        sprintf(pth,"%s/%s",directory,(*dirent).d_name); //store directory path inside pth array
        struct stat stts;
        if(lstat(pth, &stts)==-1){
            printf("Error getting the status for '%s'\n", pth);
            continue;
        }
        int ogDep= dirDep+1;
        char prntnm[1000];
        //check if symbolic link to display name and name the link points to
        if(S_ISLNK(stts.st_mode)){
            char trgt[500];
            int len=readlink(pth,trgt,sizeof(trgt)-1);
            if(len!=-1){
                trgt[len]='\0';
                sprintf(prntnm,"%s (%s)",(*dirent).d_name,trgt);
            }
            else{
                sprintf(prntnm,"%s",(*dirent).d_name);
            }
        }
        else{
            sprintf(prntnm,"%s",(*dirent).d_name);
        }
        int temp=allarg((*dirent).d_name, stts, ogDep);
        if(S_ISDIR(stts.st_mode)){
            if(temp){
                prnt(prntnm,stts,dirDep);
            }
            traverse(pth,ogDep);
        }
        else{
            if(temp){
                prnt(prntnm,stts,dirDep);
            }
        }

    }
    closedir(parentDir);
}

int main (int argc, char **argv) { 
    char strt[500];
    strcpy(strt,".");
    int i;
    //check that all arguments are given for not only the program
    //execution, but also for each special command
    for(i=1;i<argc;i++){
        if(strcmp(argv[i],"-S")==0){
            SCom=1;
        }
        else if(strcmp(argv[i],"-s")==0){
            sCom=1;
            i++;
            sSize=atol(argv[i]);
        }
        else if(strcmp(argv[i],"-f")==0){
            fCom=1;
            i++;
            strcpy(fStr,argv[i]);
            i++;
            fDep=atoi(argv[i]);
        }
        else if(strcmp(argv[i],"-t")==0){
            tCom=1;
            i++;
            tType=argv[i][0];
        }
        else{
            strcpy(strt,argv[i]);
        }
    }
    struct stat root;
    if(lstat(strt, &root)==-1 || !S_ISDIR(root.st_mode)){
        printf("Error: '%s' is not a valid directory\n",strt);
        exit(-1);
    }
    traverse(strt,0);
    return 0;
}