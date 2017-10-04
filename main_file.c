#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include <math.h>

//gcc -Wall main_file.c -o  main_file -lm -w

unsigned char *macqual[500][2];
FILE *fp;
int line_num = 1;
int rssi=0;
int find_result, x, i, j, jj, loss_rate, loss_rate_last, diff, predicted_bw, achieved_bw, BW_ratio = 0;
char temp[112];
unsigned char *lineArray[500][2];
double ratio=0;
int dummy1, dummy2;
	

int rate, rate1=0;
FILE *fp2;
int find_result2=0;
char temp2[112];
unsigned char *lineArray2[500][2];
unsigned char *macqual2[500][2];



FILE *fp3;
int find_result3=0;
char temp3[112];
unsigned char *lineArray3[500][2];
unsigned char *macqual3[500][2];

int rtt=0, loss=0;
FILE *fp5, *fp6;
int find_result5,find_result6=0;
char temp[112];
unsigned char *lineArray5[500][2];
unsigned char *macqual5[500][2];
unsigned char *lineArray6[500][2];
unsigned char *macqual6[500][2];
int line_num_5 = 1,x_5=0;
int line_num_6 = 1,x_6=0;



unsigned char *trim(unsigned char *s) {
  while (isspace((unsigned char) *s)) s++;
  if (*s) {
    unsigned char *p = s;
    while (*p) p++;
    while (isspace((unsigned char) *(--p)));
    p[1] = '\0';
  }
  return s;
}


char *trimwhitespace(unsigned char *str)
{
  unsigned char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}


int str_cut(unsigned char *str, int begin, int len)
{
    int l = strlen(str);

    if (len < 0) len = l - begin;
    if (begin + len > l) len = l - begin;
    memmove(str + begin, str + begin + len, l - len + 1);

    return len;
}


int Search_loss(char *fname, char *str1) {
	
	
	if((fp = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}

	

	while(fgets(temp, 112, fp) != NULL) 
	{
		
	 //  if((strstr(temp, str1)) != NULL) 
		{
			lineArray[x][0] = malloc(strlen(temp));
			strcpy(lineArray[x][0], temp);
			trim(lineArray[x][0]);
			str_cut(lineArray[x][0], 0, 21);
			find_result++;
			x++;
		}
			
			
		line_num++;
		
	}
	

	if(find_result == 0) {
		//printf("\nSorry, couldn't find a match.\n");
	}
	

	if(fp) {
		fclose(fp);
	}



	
	
   	return(0);
}






int search_rssi(char *fname) {
	FILE *fp1;
	
	
	char temp[112];
		
	if((fp1 = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}


	while(fgets(temp, 112, fp1) != NULL) 
	{					
		rssi++;
		
	}
	
	
	if(fp1) {
		fclose(fp1);
	}
		

   	return(rssi);
}



int search_rate(char *fname, char *str1, char *str2) {
	
	if((fp2 = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}

	while(fgets(temp2, 112, fp2) != NULL) 
	{
		
	if((strstr(temp2, str1)) != NULL)  //qual
		{
			lineArray2[0][0] = malloc(strlen(temp2));
			strcpy(lineArray2[0][0], temp2);
			trim(lineArray2[0][0]);
			str_cut(lineArray2[0][0], 20, 29);
			
		}
	if((strstr(temp2, str2)) != NULL) //ssid
		{
			lineArray2[0][1] = malloc(strlen(temp2));
			strcpy(lineArray2[0][1], temp2);
			trim(lineArray2[0][1]);
			find_result2++;
		}
		
	}
	if(find_result2 == 0) {
		//printf("\nSorry, couldn't find a match.\n");
	}
	
	if(fp2) {
		fclose(fp2);
	}
		  macqual2[0][0]=trimwhitespace(lineArray2[0][0]);
		  macqual2[0][0]=strtok (macqual2[0][0]," =/");
		  rate=atoi(macqual2[0][0]);

	  return(rate);
}


int search_rate1(char *fname, char *str1, char *str2) {
	
	if((fp3 = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}

	while(fgets(temp3, 112, fp3) != NULL) 
	{
		
	if((strstr(temp3, str1)) != NULL)  //qual
		{
			lineArray3[0][0] = malloc(strlen(temp3));
			strcpy(lineArray3[0][0], temp3);
			trim(lineArray3[0][0]);
			str_cut(lineArray3[0][0], 20, 29);
			
		}
	if((strstr(temp3, str2)) != NULL) //ssid
		{
			lineArray3[0][1] = malloc(strlen(temp3));
			strcpy(lineArray3[0][1], temp3);
			trim(lineArray3[0][1]);
			find_result3++;
		}
		
	}
	if(find_result3 == 0) {
		//printf("\nSorry, couldn't find a match.\n");
	}
	
	if(fp3) {
		fclose(fp3);
	}
		  macqual3[0][0]=trimwhitespace(lineArray3[0][0]);
		  macqual3[0][0]=strtok (macqual3[0][0]," =/");
		  rate1=atoi(macqual3[0][0]);

	  return(rate1);
}

int Search_loss_new(char *fname, char *str1) {
	
	
	if((fp5 = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}

	

	while(fgets(temp, 112, fp5) != NULL) 
	{
		
	
		{
			lineArray5[x_5][0] = malloc(strlen(temp));
			strcpy(lineArray5[x_5][0], temp);
			trim(lineArray5[x_5][0]);
			str_cut(lineArray5[x_5][0], 0, 20);
			find_result5++;
			x_5++;
		}
			
			
		line_num_5++;
		
	}
	

	if(find_result5 == 0) {
		//printf("\nSorry, couldn't find a match.\n");
	}
	

	if(fp5) {
		fclose(fp5);
	}



	
	
   	return(0);
}


int Search_rtt(char *fname, char *str1) {
	
	
	if((fp6 = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}

	

	while(fgets(temp, 112, fp6) != NULL) 
	{
		
	
		{
			lineArray6[x_6][0] = malloc(strlen(temp));
			strcpy(lineArray6[x_6][0], temp);
			trim(lineArray6[x_6][0]);
			str_cut(lineArray6[x_6][0], 0, 20);
			find_result6++;
			x_6++;
		}
			
			
		line_num_6++;
		
	}
	

	if(find_result6 == 0) {
		//printf("\nSorry, couldn't find a match.\n");
	}
	

	if(fp6) {
		fclose(fp6);
	}

	
	
   	return(0);
}






int main(int argc, char *argv[]) {
	int result;
	
	result = Search_loss_new("loss_rate_final.txt", "lss");
	result = Search_rtt("rtt.txt", "rtt");
	
	if(result == -1) {
		perror("Error");
		exit(1);
	}

		
	macqual5[0][0]=trimwhitespace(lineArray5[line_num_5-2][0]);
	loss= atoi(macqual5[0][0]); 
	macqual6[0][0]=trimwhitespace(lineArray6[line_num_6-2][0]);
	rtt= atoi(macqual6[0][0]); 
	printf("current rtt value=%d \n",rtt);
	printf("current loss rate=%d \n",loss);
	printf("sqrt=%f \n",sqrt(1000)/sqrt(loss));
	predicted_bw=8*1328*2*sqrt(1000)/(sqrt(loss)*rtt);   //predicted BW
	
	result = search_rate("rate.txt", ".",".");
	if(result == -1) 
		{
		perror("Error");		
		exit(1);
		}
	
	achieved_bw=rate*8;
	BW_ratio=100*(predicted_bw-achieved_bw)/achieved_bw;							
	printf ("achieved BW : %d Kbps, predicted BW=%d Kbps, ratio= %d \n",achieved_bw, predicted_bw, BW_ratio);      // real BW

	search_rssi("/home/lab123/Desktop/list1.txt");
	printf("Number of acceptable access point available =%d\n",(rssi-1));
	
	
	sleep(5);
 	result = search_rate1("rate.txt", ".",".");
 	if(result == -1) 
		{
			perror("Error");		
			exit(1);
		}	
								
	printf ("checking wether we have a subflow or not.....\n");	
	if (rate1 > 5)
	{
		printf("we have a subflow..\n",rate);
		
		if (rssi == 1)
			{

			 if(fork()==0)
		 		{ 
					printf("rssi of a existing sub-flow falls, disconnectiong that one....\n");
					char *argv[] = { "/sbin/ip", "link", "set", "dev", "wlan1", "multipath", "off", NULL };
					//char *argv[] = { "/usr/bin/nmcli", "dev", "disconnect", "iface", "eth2", NULL };
   					static char *envp[] = {
      		 			"HOME=/",
       					"TERM=linux",
        				"PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
  					execve(argv[0], argv, envp);
   					fprintf(stderr, "Oops!\n");       			   
					return 0;  
	 			}


			}
	
	} else printf("We dont have a subflow.. \n");


	
	 if (loss_rate> 2 && rssi > 1 && rate1 < 1) 
		{
		
		 for (i=0; i<2; i++) 
	  	  {
		 
			 if(i==0 && fork()==0)
		 		{ 
					printf ("Loss rate > 1 and RSSI ok: setting up new subflow \n");
					//char *argv[] = { "/sbin/ip", "link", "set", "dev", "wlan1", "multipath", "on", NULL };
					char *argv[] = { "/usr/bin/nmcli", "dev", "wifi","connect", "OpenWrt1_5GhZ","password","ascp2016","iface","eth2", NULL };
   					static char *envp[] = {
      		 			"HOME=/",
       					"TERM=linux",
        				"PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
  					execve(argv[0], argv, envp);
   					fprintf(stderr, "Oops!\n");       			   
					return 0;  
	 			}
       			  if(i==1 && fork()==0)
				{ 
					        printf("waiting for new subflow performance test...........\n");
						sleep(50);						
						printf (" searching new loss rate.....\n");
						result = Search_loss(argv[1], argv[2]);
						if(result == -1) {
							perror("Error");
							exit(1);
						 }

						macqual[0][0]=trimwhitespace(lineArray[line_num-2][0]);
						loss_rate= atoi(macqual[0][0]); 
						diff= loss_rate_last-loss_rate;
						ratio=100*(loss_rate_last-loss_rate)/loss_rate_last;
						printf("new loss rate=%d improvement ratio=%0.1f\n",loss_rate, ratio);

						if (diff<3) 

							{
							        result = search_rate("rate.txt", ".",".");
								if(result == -1) 
								{
									perror("Error");		
									exit(1);
								}	
								
						printf ("achieved rate from new subflow: %d KBps\n",rate);	
								if (rate < 300)
									{
									printf("Rate=%d not OK : less than 300. Disconnecting...\n",rate);
						//char *argv[] = { "/sbin/ip", "link", "set", "dev", "wlan1", "multipath", "off", NULL };
							char *argv[] = { "/usr/bin/nmcli", "dev", "disconnect", "iface", "eth2", NULL };
   									static char *envp[] = {
      		 							"HOME=/",
       									"TERM=linux",
        								"PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
  									execve(argv[0], argv, envp);
   									fprintf(stderr, "Oops!\n");   
									}



							}

						//printf ("ext child2\n");
						return 0;
				}
		 
			 wait(&dummy1);
			 wait(&dummy2);
	 
		  }
		}



	if (loss_rate < 2 && rate1 > 5) 
				{ printf("loss rate improved and below 10, mptcp subflow turning off.......\n");
				 //char *argv[] = { "/sbin/ip", "link", "set", "dev", "wlan1", "multipath", "off", NULL };
				char *argv[] = { "/usr/bin/nmcli", "dev", "disconnect", "iface", "eth2", NULL };
   				 static char *envp[] = {
      		 		 "HOME=/",
       				 "TERM=linux",
        			 "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
  				 execve(argv[0], argv, envp);
   				 fprintf(stderr, "Oops!\n");
								
				}  
		 	
		 	
	

	return(0);
}
