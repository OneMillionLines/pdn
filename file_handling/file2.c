#include <stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE *input = fopen("1.txt", "rb+"); 
	int pos;
	char character;char ch[100];
	scanf("%d %c", &pos, &character); 
	fseek(input, pos, SEEK_SET); 
	
	fprintf(input, "%c", character);
	while(input!=NULL)
	{
	
	ch=fgetc(input);
	printf("%s",ch);
	}fclose(input);
	return 0;
}

