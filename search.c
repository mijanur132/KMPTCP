#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

/* void Usage(char *filename) {
	printf("Usage: %s <file> <string>\n", filename);
	printf("%s version 1.0 \nCopyright(c) CodingUnit.com\n", filename);
}
 //*/

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


int Search_in_File(char *fname, char *str1, char *str2) {
	FILE *fp;
	int line_num = 1;
	int find_result, x, i, j = 0;
	char temp[112];
	unsigned char *lineArray[500][2];
	unsigned char *macqual[500][2];
	
	if((fp = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}

	

	while(fgets(temp, 112, fp) != NULL) 
	{
		
	if((strstr(temp, str1)) != NULL)  //qual
		{
			lineArray[x][0] = malloc(strlen(temp));
			strcpy(lineArray[x][0], temp);
			trim(lineArray[x][0]);
			str_cut(lineArray[x][0], 20, 29);
			
			
		}
	if((strstr(temp, str2)) != NULL) //ssid
		{
			lineArray[x][1] = malloc(strlen(temp));
			strcpy(lineArray[x][1], temp);
			trim(lineArray[x][1]);
			//str_cut(lineArray[x][0], 9, 20);
			find_result++;
			x++;
		}
			
			
		line_num++;
		
	}
	

	if(find_result == 0) {
		//printf("\nSorry, couldn't find a match.\n");
	}
	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
		printf("\n");
	for (i=0; i<x; i++)
	{
		for (j=0; j<2; j++)
		{   macqual[i][j]=trimwhitespace(lineArray[i][j]);
		 	macqual[i][j]=strtok (macqual[i][j]," =/");
		 	 if (atoi(macqual[i][0]) > 87) 
				{
					continue;
				}  
			printf("%s ", macqual[i][j]);
		
		} 
		// if (atoi(macqual[i][0]) > 70) { continue;};
		//printf("\n");
		
	}

	
	
   	return(0);
}




int main(int argc, char *argv[]) {
	int result;

	if(argc < 4 || argc > 4) {
	
		exit(1);
	}

	system("clear"); 


	result = Search_in_File(argv[1], argv[2], argv[3]);
	if(result == -1) {
		perror("Error");
		
		exit(1);
	}
	return(0);
}
