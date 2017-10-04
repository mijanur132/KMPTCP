#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>


unsigned char *macqual[500][2];
FILE *fp;
int line_num = 1;
int rssi=0;
int find_result, x, i, j, jj, loss_rate, loss_rate_last, diff = 0;
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
			//str_cut(lineArray3[0][0], 20, 29);
			
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





int main(void)
{	
					
	int result;
	
	result = search_rate1("rate.txt", ".",".");
 	if(result == -1) 
		{
			perror("Error");		
			exit(1);
		}	
								
	
	
	
	printf("current rate=%d \n", rate1);
	
	
	return 0;  	
	
}


