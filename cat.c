#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

int main(int argc , char* argv[]) {

 
    char line[250];
  
    FILE *cf;
    if (argc==2){
      
        cf = fopen(argv[1],"r");
    }
    else {
        
        cf = fopen(argv[2],"r");
    }
    
    if (argv[2]==NULL) {

    while (fgets(line, sizeof(line), cf)) 
    { 
        printf ("  %s", line); 
 
    }
    fclose(cf);
    }

    else if (strcmp(argv[1],"-n")==0) {
    int j =1;

    while (fgets(line, sizeof(line), cf)) 
    { 
        printf("  %d",j);
        printf("  %s",line);
        j++; 
    
    }

    fclose(cf);

    }

    else if (strcmp(argv[1],"-E")==0) {

    while (fgets(line, sizeof(line), cf)) 
    { 
     
        char *t = strtok(line,"\n");
        printf (" %s$", t);
        printf("\n"); 

    }
    fclose(cf);
    }

    return 0;
}