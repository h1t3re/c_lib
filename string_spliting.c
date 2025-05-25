#include <stdlib.h>
#include <stdio.h>
#include "c_lib.h"

char **string_spliting(char *string, char *spliter)
{
	char *temporary_array = (char *)malloc(strlen(spliter)*sizeof(char));
	char **arrays = (char **)malloc(sizeof(char *));	
	int position_in_arrays = 0;
	int position_in_string = 0;
	int position_of_string = 0;
	int string_length = 0;
	int j = 0;
	int i = 0;
	while(*(string+position_in_string+j) != '\0')
	{
		if(position_in_string == 0)
			arrays[position_in_arrays] = (char *)malloc((position_in_string+1)*sizeof(char));
		else
			arrays[position_in_arrays] = (char *)realloc(arrays[position_in_arrays], (position_of_string+1)*sizeof(char));

		temporary_array[j] = string[position_in_string+j];

		arrays[position_in_arrays][position_of_string] = string[position_in_string+j];	
		j++;
		//position_in_string++;
		position_of_string++;	
		temporary_array[j] = '\0';
		arrays[position_in_arrays][position_of_string] = '\0';
		printf("%s\n", arrays[position_in_arrays]);
		if(strcmp(strdup(temporary_array),strdup(spliter))) 
		{
			position_in_arrays++;
			arrays = (char **)realloc(arrays, (position_in_arrays+1)*sizeof(char *));
			arrays[position_in_arrays] = '\0';
			position_of_string = 0;
		}
		if((j == strlen(spliter)) & (j == strlen(temporary_array)))
		{
			position_in_string = position_in_string+j;
			j = 0;
		}
		//while(& (string[position_in_string+j] != '\0'));	
		
	}
	arrays[position_in_arrays] = '\0';
	free(temporary_array);
	return arrays;
}

int main()
{
	char *string = strdup("0 1 2 3 4 5 6 7 8 9\0");
	char *spliter = strdup(" \0");
	int i = 0;
	char **arrays = string_spliting(strdup(string), strdup(spliter));
	while(arrays[i] != '\0')
	{
		printf("%s", arrays[i]);
		i++;	
	}
	free(string);
	free(spliter);
	while(*(arrays+(i*sizeof(char *))) != '\0')
	{
		free(arrays[i]);
		i++;
	}
	free(arrays);
	return 0;
}
