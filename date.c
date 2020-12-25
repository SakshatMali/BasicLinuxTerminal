#include <stdio.h> 
#include <time.h>     
#include <string.h>
int main(int argc , char* argv[]) {

    time_t local_time;

	struct  tm *ptr;

	char arr[1000];


	local_time = time(NULL);
    
		if(argv[1]==NULL)
	{
		local_time = time(NULL);
		printf("%s",ctime(&local_time));

	}
	else if(strcmp(argv[1],"-u")==0)
	{
		
		//time(global_time);
		ptr = gmtime(&local_time);
		strftime(arr, 1000, "%c", ptr);
		printf("%s\n",arr );
	}
	else if(strcmp(argv[1],"-R")==0)
	{
		ptr = localtime(&local_time);
		strftime(arr, 1000, "%a %d %h %Y %T %z", ptr);
		printf("%s\n",arr );
	}

    return 0;
}