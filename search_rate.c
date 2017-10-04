#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int rate=0;
FILE *fp2;
int find_result2=0;
char temp[112];
unsigned char *lineArray2[500][2];
unsigned char *macqual2[500][2];


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


int search_rate(char *fname, char *str1, char *str2) {
	
	if((fp2 = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}

	while(fgets(temp, 112, fp2) != NULL) 
	{
		
	if((strstr(temp, str1)) != NULL)  //qual
		{
			lineArray2[0][0] = malloc(strlen(temp));
			strcpy(lineArray2[0][0], temp);
			trim(lineArray2[0][0]);
			str_cut(lineArray2[0][0], 20, 29);
			
		}
	if((strstr(temp, str2)) != NULL) //ssid
		{
			lineArray2[0][1] = malloc(strlen(temp));
			strcpy(lineArray2[0][1], temp);
			trim(lineArray2[0][1]);
			find_result2++;
		}
		
	}
	if(find_result2 == 0) {
		printf("\nSorry, couldn't find a match.\n");
	}
	
	if(fp2) {
		fclose(fp2);
	}
		  macqual2[0][0]=trimwhitespace(lineArray2[0][0]);
		  macqual2[0][0]=strtok (macqual2[0][0]," =/");
		  rate=atoi(macqual2[0][0]);
	  return(rate);
}




int main() {
	int result;
	
	result = search_rate("rate.txt", ".",".");
	if(result == -1) {
		perror("Error");
		
		exit(1);
	}
	
	printf("Rate=%d\n",rate);
	
	return(0);
}
