#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int rtt=0;
FILE *fp2;
int find_result2=0;
char temp[112];
unsigned char *lineArray2[500][2];
unsigned char *macqual2[500][2];
int line_num = 1,x=0;

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
	
	
	if((fp2 = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}

	

	while(fgets(temp, 112, fp2) != NULL) 
	{
		
	
		{
			lineArray2[x][0] = malloc(strlen(temp));
			strcpy(lineArray2[x][0], temp);
			trim(lineArray2[x][0]);
			str_cut(lineArray2[x][0], 0, 20);
			find_result2++;
			x++;
		}
			
			
		line_num++;
		
	}
	

	if(find_result2 == 0) {
		printf("\nSorry, couldn't find a match.\n");
	}
	

	if(fp2) {
		fclose(fp2);
	}



	
	
   	return(0);
}



int main() {
	int result;
	
		result = Search_loss("loss_rate_final.txt", "rtt");
		if(result == -1) {
		perror("Error");
		exit(1);
	}

	
	macqual2[0][0]=trimwhitespace(lineArray2[line_num-2][0]);
	rtt= atoi(macqual2[0][0]); 
	printf("current loss rate=%d \n",rtt);
	
	return(0);
}
