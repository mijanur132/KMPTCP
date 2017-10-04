#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

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





int main() {
	int result;
	
		
		result = Search_loss("loss_rate_final.txt", "lss");
		result = Search_rtt("rtt.txt", "rtt");
		if(result == -1) {
		perror("Error");
		exit(1);
	}

	
	macqual5[0][0]=trimwhitespace(lineArray5[line_num_5-2][0]);
	macqual5[1][0]=trimwhitespace(lineArray5[line_num_5-3][0]);
	macqual6[0][0]=trimwhitespace(lineArray6[line_num_6-2][0]);
	macqual6[1][0]=trimwhitespace(lineArray6[line_num_6-3][0]);
	loss= atoi(macqual5[0][0]+macqual5[1][0]); 
	rtt= atoi(macqual6[0][0]+macqual6[1][0]); 


	printf("current rtt rate=%d \n",rtt);
	printf("current loss rate=%d \n",loss);
	
	return(0);
}
