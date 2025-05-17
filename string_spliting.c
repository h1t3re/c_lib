#include <stdlib.h>
#include <stdio.h>
#include "c_lib.h"

char **string_spliting(char *string, char *spliter)
{
	char **arrays = (char **)malloc(sizeof(char *));
	char *temporary_array = (char *)malloc(strlen(spliter)*sizeof(char));
	int position_in_arrays = 0;
	int position_in_string = 0;
	int string_length = 0;
	int j = 0;
	while(*(string+position_in_string) != '\0')
	{
		while(!strcmp(strdup(temporary_array),strdup(spliter)))
		{
			*(temporary_array + (j*sizeof(char))) = *(string + ((position_in_string+j)*sizeof(char)));

			*(*(arrays+(position_in_arrays*sizeof(char *)))+(position_in_string)*sizeof(char)) = *(string + (position_in_string*sizeof(char)));	
			j++;
			position_in_string++;
		}
		j = 0;
		printf("%s\n", *(arrays+(position_in_arrays*sizeof(char *))));
		position_in_arrays++;
		arrays = (char **)realloc(arrays, (position_in_arrays+1)*sizeof(char *));
	}
	*(arrays +(position_in_arrays*(sizeof(char*)))) = '\0';
	return arrays;
}

int main()
{
	char *string = strdup("00 11 22 33 44 55 66 77 88 99\0");
	char *spliter = strdup("  \0");
	int i = 0;
	char **arrays = string_spliting(strdup(string), strdup(spliter));
	while(*(arrays+(i*sizeof(char *))))
	{
		printf("%s\n", *(arrays+(i*sizeof(char *))));
		i++;
	}
	return 0;
}
