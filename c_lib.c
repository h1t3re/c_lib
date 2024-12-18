#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int strlen(const char *str)
{
        long unsigned int length = 0;
        while(*(str+(length*sizeof(char))) != '\0')
        {
                length = length +1;
        }
        return length;
}

const int strcmp(const char *str0, const char *str1)
{
        int i = 0;
        while((str0[i] == str1[i]) & ((str0[i] != '\0') | (str1[i] != '\0')))
        {
                i = i +1;
        }
        if((i != strlen(str0)) | (i != strlen(str1)))
                return 1;
        return 0;
}

char *strdup(const char *str)
{
        char *dupofstr = (char *)malloc((strlen(str)+1)*sizeof(char));
        if(dupofstr == NULL)
                return NULL;
        int length = 0;
        while(str[length] != '\0')
        {
                dupofstr[length] = str[length];
                length = length +1;
        }
        dupofstr[length] = str[length];
        return dupofstr;
}

const int strcontains(const char *str0, const char *str1)
{
        int i = 0, j = 0;
        while(str0[i+j] != '\0')
        {
                if((str0[i+j] == str1[j]) & (str1[j] != '\0'))
                {
                        j = j +1;
                }
                else{
                        i = i +1;
                        j = 0;
                }
                if(j == strlen(str1))
                {
                        return 0;
                }
        }
        return 1;
}

char *strconcatenate(const char *str0, const char *str1)
{
        char *buffer = strdup(str0);
        const char *str = strdup(str1);
        int lengh0 = strlen(str0);
        int lengh1 = strlen(str1);
        int i = lengh0;
        buffer = (char *)realloc(buffer, (lengh0+lengh1)*sizeof(char));
        if(buffer == NULL)
                return NULL;
        while((i < (lengh0+lengh1)) & (str[i-lengh0] != '\0'))
        {
                buffer[i] = str[i-lengh0];
                i = i +1;
        }
        buffer[i] = '\0';
        return buffer;
}

char *readi()
{
        char *buffer = (char *)malloc(2*sizeof(char));
        char *buffer_buffer_len_content = (char *)malloc(2*sizeof(char));
        char *end_of_line = (char *)malloc(2*sizeof(char));
        int buffer_len = 0;
        *buffer = ' ';
        *(buffer+sizeof(char)) = '\0';
        *end_of_line = '\n';
        *(end_of_line+sizeof(char)) = '\0';
        snprintf(buffer_buffer_len_content, 2*sizeof(char), "%c\0", *(buffer+buffer_len));
        while(strcmp(buffer_buffer_len_content, end_of_line) != 0)
        {
                read(1, &(*(buffer+(buffer_len*sizeof(char)))), sizeof(char));
                snprintf(buffer_buffer_len_content, 2*sizeof(char), "%c\0", *(buffer+(buffer_len*sizeof(char))));
                buffer_len = buffer_len + 1;
                buffer = (char *)realloc(buffer, (buffer_len+2)*sizeof(char));
                *(buffer+(buffer_len*sizeof(char))) = '\0';
        }
        free(buffer_buffer_len_content);
        free(end_of_line);
        return buffer;
}

char *read_file(const char *restrict file_name)
{
        const char *restrict mode = strdup("r\0");
        FILE *restrict fd = fopen(file_name, mode);
        if(fd == NULL)
                return NULL;
        char *buffer = (char *)malloc(sizeof(char));
        int buffer_len = 0;
        do
        {
                buffer_len = buffer_len +1;
                fread(buffer+((buffer_len-1)*sizeof(char)), sizeof(char), 1, fd);
                buffer = (char *)realloc(buffer, (buffer_len+1)*sizeof(char));
        }while(*(buffer+((buffer_len-1)*sizeof(char))) != EOF);
        *(buffer+((buffer_len-1)*sizeof(char))) = '\0';
        return buffer;
}

char *read_file_v1(char *file_name)
{
        const char *restrict mode = strdup("r\0");
        FILE *restrict fd = fopen(file_name, mode);
        if(fd == NULL)
                return NULL;
        char *buffer = (char *)malloc(sizeof(char));
        int buffer_len = 0;
        while((buffer[buffer_len] = fgetc(fd)) != EOF)
        {
                buffer_len++;
                buffer = (char *)realloc(buffer, (buffer_len+1));
        }
        buffer[buffer_len] = '\0';
        return buffer;
}

const int shift_mask_left(const int mask, const int i)
{
        const int mask_shifted = mask << i;
        return mask_shifted;
}

const int and_operation(const int number, const int mask_shifted)
{
        const int result = number & mask_shifted;
        return result;
}

const int shift_result_right(const int number, const int i)
{
        const int result = number >> i;
        return result;
}

void convert_integer_to_binary(int *restrict array, const int number, const int mask, const int architecture)
{
        int i = 0;
        while(i < architecture)
        {
                const int mask_shifted = shift_mask_left(mask, i);
                const int and_result = and_operation(number, mask_shifted);
                array[i] = shift_result_right(and_result, i);
                i = i +1;
        }
}

double pow(double x, double y)
{
        if(y == 1)
                return x;
        return pow(x*x, y-1);
}

int convert_binary_to_integer(int *array, int architecture)
{
        int number = 0;
        int i = architecture-1;
        while(i >= 0)
        {
                if(array[i] == 1)
                        number = number + pow(2, i+1);
                i = i -1;
        }
        return number;
}

int *concatenate_arrays_of_int(int *restrict array0, int length0, int *restrict array1, int length1)
{
        int i = 0;
        int j = 0;
        int length = 0;
        int *array = (int *)malloc((length0+length1)*sizeof(int));

        while(i < length0)
        {
                array[i] = array0[i];
                i = i +1;
        }
        while(i < (length0+length1))
        {
                array[i] = array1[i-length0];
                i = i +1;
        }
        return array;
}
