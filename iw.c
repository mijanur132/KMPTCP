#include <unistd.h>
#include <stdio.h>

int main(void)
{	 //pid_t  pid;
     int dummy1, dummy2;
     int i, jj=0;
     for (i=0; i<2; i++) 
	 {
		 
		 if(i==0 && fork()==0)
		 			{ 
					printf ("\n entered child1 \n");
					for (jj=1; jj<500000000; jj++){};
       			    char *argv[] = { "/bin/bash", "-c", "/sbin/iwlist wlan0 scan > /home/lab123/Desktop/list", NULL};
  					 static char *envp[] = {
     				   "HOME=/",
      				  "TERM=linux",
      				  "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
   					 execve(argv[0], argv, envp);
						for (jj=1; jj<500000000; jj++){};
					 
						printf ("\n ext child1 \n");
		 				return 0;  
	 				}
         if(i==1 && fork()==0)
					{ 
						for (jj=1; jj<1000000000; jj++){};
						
					 printf ("entered child2");
					char *argv1[] = { "/bin/bash", "-c", "/home/lab123/Desktop/srch list Qua 1_5GhZ > /home/lab123/Desktop/list1.txt", NULL}; // 
   					 static char *envp1[] = {
    				    "HOME=/",
    				    "TERM=linux",
    				    "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
   					 execve(argv1[0], argv1, envp1);
					for (jj=1; jj<500000000; jj++){};
					
					// printf ("ext child2");
					 return 0;
					 }
		 
		 wait(&dummy1);
		 wait(&dummy2);
		 
		 
		 
	 }
         return 0;
		 

}

