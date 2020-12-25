#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
int main(int argc , char* argv[]){

    if (argc==2) {

        struct stat ts = {0};
        if (stat(argv[1] , &ts)==-1) {
            mkdir(argv[1],0700);
        } else {
            printf("Directory already exsist cannot be created\n");
        }

     }

    else if (argc==3) {

        struct stat ts = {0};

        if (strcmp(argv[1],"-v")==0 && stat(argv[2] , &ts)==-1) {
        printf("mkdir: created directory '%s'",argv[2]);
        mkdir(argv[2],0700);
        }
        else {
            printf("Directory already exsist cannot be created\n");
        }
    } 

    else if (argc==4) {

        struct stat ts = {0};

        if (strcmp(argv[1],"-m")==0 && stat(argv[3] , &ts)==-1) {
        printf("Created directory with desired mode '%s'\n",argv[3]);
        mkdir(argv[3],0700); 
        }
        else {
            printf("Directory already exsist cannot be created\n");
        }
    } 

    return 0;
}