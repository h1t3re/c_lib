#include <stdlib.h>
#include <stdio.h>
#include "c_lib.h"

char **string_spliting(char *string, char *spliter)
{
	char *temporary_array = (char *)malloc(strlen(spliter)*sizeof(char));;
	char **arrays = (char **)malloc(sizeof(char *));	
	int position_in_arrays = 0;
	arrays[position_in_arrays] = (char *)malloc(strlen(spliter)*sizeof(char));
	int position_in_string = 0;
	int position_of_string = 0;
	int j = 0;
	int i = 0;
	while(*(string+position_in_string+j) != '\0')
	{
		
		while(j < strlen(spliter))
		{
			temporary_array[j] = string[position_in_string+j];
			j++;
		}
		temporary_array[j] = '\0';
		position_in_string = position_in_string +1;
		printf("tmp = \'%s\'\n", temporary_array);
		j = 0;
		printf("comparaison(\'%s\', \'%s\') = %d\n", strdup(temporary_array), strdup(spliter), strcmp(strdup(temporary_array), strdup(spliter)));
		if(strcmp(strdup(temporary_array), strdup(spliter)) != 0)
		{
			printf("in if\n");
			++i;
			arrays[position_in_arrays] = strconcatenate(strdup(arrays[position_in_arrays]), strdup(temporary_array));
			position_of_string = position_of_string + strlen(spliter);
			arrays[position_in_arrays][position_of_string] = '\0';
			printf("arrays[%d] = %s\n", position_in_arrays, arrays[position_in_arrays]);
		}else
		{			
			printf("in else\n");
			arrays[position_in_arrays][position_of_string] = '\0';
			free(temporary_array);
			temporary_array = (char *)malloc(strlen(spliter)*sizeof(char));
			position_in_arrays++;
			arrays = (char **)realloc(arrays, (position_in_arrays+1)*sizeof(char *));
			arrays[position_in_arrays] = (char *)malloc(strlen(spliter)*sizeof(char));
		}
	}
	arrays[position_in_arrays] = '\0';
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
		printf("%d = %s\n", i, arrays[i]);
		i++;	
	}
	
	while(arrays[i] != '\0')
	{
		free(arrays[i]);
		i++;
	}
	free(string);
	free(spliter);
	free(arrays);
	return 0;
}
