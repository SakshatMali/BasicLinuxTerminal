#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

void echo(char st[]) {
    printf("%s\n",st);
}

void history() {
    char l[250];
    FILE *hf;
    hf = fopen("history.txt","r");
     
    while (fgets(l, sizeof(l), hf)) 
    { 
        printf (" %s", l); 
    }
    fclose(hf);

}

void historys(int s) {
    char l[250];
    FILE *hf;
    hf = fopen("history.txt","r");
    int k =1;
    while (fgets(l, sizeof(l), hf)) 
    { 
        if (k==s) {
            continue;
        }
        else {
        printf (" %s", l); 
        }
    }
    fclose(hf);

}

void pwd() {
    char dir[1024];
	getcwd(dir,sizeof(dir));
	printf("%s\n", dir );
}

void cd(char di[]) {
    chdir(di);
}

int exiting() {
    return 0;
}

int main() {
    
    char *lspath;
	lspath=realpath("./ls",NULL);
	char *datepath;
	datepath=realpath("./date",NULL);
	char *mkdirpath;
	mkdirpath=realpath("./mkdir",NULL);
	char *rmpath;
	rmpath=realpath("./rm",NULL);
	char *catpath;
	catpath=realpath("./cat",NULL);

    int loop=1;

    FILE *fp;
    fp=fopen("history.txt","w");

    while (loop) {

        printf("Shell:$\n");
        printf(">> ");

        char co[10][100];
        int byt;
        size_t sz;
        char* inp;
        inp = (char*)malloc(sz);
        byt = getline(&inp , &sz , stdin);
        fputs(inp,fp);

        char *to = strtok(inp , " \n");
        int i =0;

        while(to!=NULL) {
	        strcpy(co[i],to);
	        i++;
            to = strtok(NULL," \n");
        }
       
        if (strcmp(co[0],"exit")==0) {
            loop=exiting();
        }

        else if (strcmp(co[0],"echo")==0) {
            
            if (strcmp(co[1],"-n")==0) {
                for (int j = 2 ; j<i ; j++) {
                    printf("%s ",*(co+j));
                }
            } 

            else if (strcmp(co[1],"-e")==0) {
                for (int j = 2 ; j<i ; j++) {
                    printf("%s",*(co+j));
                }

                printf("\n");
            } 
            
            else {
                for (int j = 1 ; j<i ; j++) {
                    printf("%s ",*(co+j));
                }

                printf("\n");

            }

        }

        else if (strcmp(co[0],"pwd")==0) {
            if (i==1) {
            pwd(); 
            }

            else if (i==2) {
                if (strcmp(co[1],"-L")==0 || 
                strcmp(co[1],"-P")==0) {
                    pwd();
                } else {
                    printf("Invalid command\n") ;
                }
            }
        }

        else if (strcmp(co[0],"history")==0) {
            
            if (i==1) {
            fclose(fp);
            history();
            fp=fopen("history.txt","a+");
            }

            if (strcmp(co[1],"-c")==0)  {
                fclose(fp);
                fp=fopen("history.txt","w");
            }

            else if (strcmp(co[1],"-d")==0) {
                int s = atoi(co[2]);
                fclose(fp);
                historys(s);
                fp=fopen("history.txt","a+");
            }

            else {
                printf("Invalid Command\n");
            }
        }

        else if (strcmp(co[0],"cd")==0) {

            if (i==1) {
                printf("Enter Argument\n");

            }

            else if (i==2) {
                cd(co[1]);
            }

            else if (i==3) {
                if (strcmp(co[1],"-L")==0 || strcmp(co[1],"-P")==0) {
                    cd(co[2]);
                }
            }

        }

        else if(strcmp(co[0],"ls")==0) {

			pid_t pid = fork();

			if(pid<0) {

				fprintf(stderr, "Fork Failed\n");
				return 1;
			}

			else if(pid==0) {

                if (i==2) {
				execl(lspath, lspath,co[1], NULL );	
                }
                else if (i==1) {
                    execl(lspath, lspath, NULL );
                }
                else {
                    printf("Invalid Command\n");
                }
			}

			else {
				wait(NULL);
			}
		}

        else if(strcmp(co[0],"date")==0) {

            pid_t pid = fork();

			if(pid<0) {

				fprintf(stderr, "Fork Failed\n");
				return 1;
			}

			else if(pid==0) {

                if (i==1) {
				execl(datepath, datepath, NULL ); 
                }

                else if (i==2) {
                execl(datepath, datepath, co[1],  NULL );
                } 

                else {
                    printf("Invalid Command\n");
                }	
			}

			else {
				wait(NULL);
			}
        }

        else if(strcmp(co[0],"mkdir")==0) {

            pid_t pid = fork();

			if(pid<0) {

				fprintf(stderr, "Fork Failed\n");
				return 1;
			}

			else if(pid==0) {
                if (i==1) {
                    printf("Enter an argument\n");
                }
                else if (i==2) {
                    
				execl(mkdirpath,mkdirpath ,co[1],NULL );
                }	

                else if (i==3) {
                execl(mkdirpath,mkdirpath ,co[1],co[2],NULL );
                }

                else if (i==4) {
                execl(mkdirpath,mkdirpath ,co[1],co[2],co[3],NULL );
                } 
                else {
                    printf("Invalid Command\n");
                }	
			}

			else {
				wait(NULL);
			}
        }

        else if(strcmp(co[0],"rm")==0) {

            pid_t pid = fork();

			if(pid<0) {
				fprintf(stderr, "Fork Failed\n");
				return 1;
			}

			else if(pid==0) {

                if (i==1) {
                    printf("Enter an Argument\n");
                }

                 else if (i==3) {
                    if (strcmp(co[1],"-i")==0) {
                        execl(rmpath,rmpath ,"-i",co[2], NULL );
                    }
                    if (strcmp(co[1],"-f")==0) {
                        execl(rmpath,rmpath ,"-f",co[2], NULL );
                    }
                }

                else if (i==2) {
				execl(rmpath,rmpath ,co[1], NULL );
                }	
			}

			else {
				wait(NULL);
			}
        }

        else if(strcmp(co[0],"cat")==0) {

            pid_t pid = fork();

			if(pid<0) {
				fprintf(stderr, "Fork Failed\n");
				return 1;
			}

			else if(pid==0) {

                if (i==1) {
                    printf("Requires an Argument\n");
                }

                else if (strcmp(co[1],"-n")==0) {
				execl(catpath,catpath ,"-n",co[2], NULL );	
                }

                else if (strcmp(co[1],"-E")==0) {
				execl(catpath,catpath ,"-E",co[2], NULL );	
                }
                else if (i==2)  {
                    execl(catpath,catpath ,co[1], NULL );
                } 
                else {
                    printf("Invalid Command\n");
                }	
			}

			else {
				wait(NULL);
			}
        }

        else {
            continue;
        } 
    }
    
    return 0;
}
