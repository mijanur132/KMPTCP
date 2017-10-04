#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int Search_in_File(char *fname) {
	FILE *fp;
	int line_num = 0;
	
	char temp[112];
		
	if((fp = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}


	while(fgets(temp, 112, fp) != NULL) 
	{					
		line_num++;
	printf("line num=%d\n", line_num);
		
	}
	
	
	
	if(fp) {
		fclose(fp);
	}
		printf("\n");

   	return(line_num);
}


int main(void)
{	
     int dummy1, dummy2, line_num;
     int i, jj=0;
     for (i=0; i<2; i++) 
	 {
		 
		 if(i==0 && fork()==0)
		 			{ 
					 char *argv[] = { "/home/lab123/Desktop/iww", NULL }; 
   						static char *envp[] = {
      				  "HOME=/",
      				  "TERM=linux",
      				  "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
  					  execve(argv[0], argv, envp);
  					  return 0;  
	 				}
         if(i==1 && fork()==0)
					{ 
						for (jj=1; jj<15000; jj++){};
						line_num = Search_in_File("/home/lab123/Desktop/list1.txt");
						
					/*	if(line_num == -1) 
						{
							perror("Error");		
							exit(1);
						}  */
	
						if (line_num > 3) 
						{
							
 							char *argv[] = { "/sbin/ip", "link", "set", "dev", "wlan1", "multipath", "on", NULL };
 							  static char *envp[] = {
  						      "HOME=/",
   							  "TERM=linux",
    						  "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
  							  execve(argv[0], argv, envp);
   							   return 0; 
																
						}
	

					 }
		 
		 wait(&dummy1);
		 wait(&dummy2);
		
		 
		 
	 }
         return 0;
		 

}





/*
int main(void)
{
	int line_num;

	line_num = Search_in_File("list1.txt");
	if(line_num == -1) 
	{
		perror("Error");
		
		exit(1);
	}
	
	if (line_num > 3) 
	{
	printf("\n line found =%d so interface turning off \n\n", line_num);
   char *argv[] = { "/sbin/ip", "link", "set", "dev", "wlan0", "multipath", "off", NULL };
   static char *envp[] = {
        "HOME=/",
        "TERM=linux",
        "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
    execve(argv[0], argv, envp);
    fprintf(stderr, "Oops!\n");
    return -1; 
		
	}
	
	return 0;
	
}
//*/
