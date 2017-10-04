#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>



int Search_in_File(char *fname) {
	FILE *fp;
	int line_num = 1;
	int find_result, x, i, j = 0;
	char temp[112];
	unsigned char *lineArray[500][2];
	
	
	if((fp = fopen(fname, "r")) == NULL) 
	{
		return(-1);
	}


	while(fgets(temp, 112, fp) != NULL) 
	{					
		line_num++;
		
	}
	printf("\n line found =%d\n", line_num);
	
	if(fp) {
		fclose(fp);
	}
		printf("\n");
	
		
   	return(0);
}


int main(int argc, char *argv[]) {
	int result, errno;


	result = Search_in_File(argv[1]);
	if(result == -1) {
		perror("Error");
		
		exit(1);
	}
	return(0);
}
