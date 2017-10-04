#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>



int Search_in_File(char *fname) {
	FILE *fp;
	int line_num = 1;
	
	char temp[112];
		
	if((fp = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}


	while(fgets(temp, 112, fp) != NULL) 
	{					
		line_num++;
		
	}
	
	
	if(fp) {
		fclose(fp);
	}
		

   	return(line_num);
}




int main(void)
{	
	 int line_num1=0; 
int line_num=0;
     int i, jj=0;
      
		 				
	
	line_num = Search_in_File("/home/lab123/Desktop/rate1.txt");
	
	//printf("line num=%d\n", line_num);
	if (line_num < 3) 
		{
			//printf("entered as line num=3\n");
   							   	
 			 char *argv[] = { "/sbin/ip", "link", "set", "dev", "wlan1", "multipath", "on", NULL };
   			static char *envp[] = {
      		 	 "HOME=/",
       			 "TERM=linux",
        		"PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
  			 execve(argv[0], argv, envp);
 			 fprintf(stderr, "Oops!\n");
	
																
		}
	
	return 0;  	
	
}
