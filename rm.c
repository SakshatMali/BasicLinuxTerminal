#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc , char* argv[]) {

    int k;
    if (argc==2) {

        struct stat ts;
        stat (argv[1],&ts);
		k = remove(argv[1]);

		if(k!=0)
		{
			printf("Invalid file name\n");
		}

        
    }

    else if (argc==3) {

    if (strcmp(argv[1],"-i")==0) {

        printf("Remove file %s ? y\n",argv[2]);

        char g[3];
        scanf("%s",g);

        if (strcmp(g,"y")==0) {
            k=remove(argv[2]);

        }
        
        if (k==0) {
            printf("File successfully deleted\n");
        }
         else {
            printf("File not deleted\n");
        }
    }

    else if (strcmp(argv[1],"-f")==0) {
        k=remove(argv[2]);
        
        if (k==0) {
        printf("File deleted forcefully\n"); 
        } 
        else {
            printf("File not deleted\n");
        }
    }
}

    return 0;
}