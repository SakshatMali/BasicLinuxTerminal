#include <stdio.h> 
#include <dirent.h>
#include <string.h> 

int main(int argc , char* argv[]) 
{ 

	if (argc==1) {
	struct dirent *st; 
	DIR *rt = opendir("."); 
	if (rt == NULL) 
	{ 
		printf("Could not open current directory" ); 
		return 0; 
	}

	while ((st = readdir(rt)) != NULL) { 
			printf("%s\n", st->d_name); 
	}
	// printf ("%s\n",argv[1]); 
	closedir(rt);

	}	

	else if (argc ==2) {
		struct dirent *st; 
		DIR *rt = opendir("."); 

		if (strcmp(argv[1],"-a")==0) {
			while ((st = readdir(rt)) != NULL) { 
			printf("%s\n", st->d_name); 
		}
		closedir(rt);

		}

		else if (strcmp(argv[1],"-i")==0) {
			int f =1;
			while ((st = readdir(rt)) != NULL) {
				printf("%d ",f);
				printf("%s\n", st->d_name); 
				f++;
	}
		closedir(rt);

		}
	} 
	return 0; 
} 
