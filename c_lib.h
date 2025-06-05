unsigned int strlen(const char *str);
const int strcmp(const char *str0, const char *str1);
char *strdup(const char *str);
const int strcontains(const char *str0, const char *str1);
char *strconcatenate(const char *str0, const char *str1);
char *readi();
char *read_file(const char *restrict file_name);
char *read_file_v1(char *file_name);
const int shift_mask_left(const int mask, const int i);
const int and_operation(const int number, const int mask_shifted);
const int shift_result_right(const int number, const int i);
void convert_integer_to_binary(int *restrict array, const int number, const int mask, const int architecture);
double pow(double x, double y);
int convert_binary_to_integer(int *array, int architecture);
int *concatenate_arrays_of_int(int *restrict array0, int length0, int *restrict array1, int length1);
int find_string_position(char *buffer, char *string, int position);
char **strsplit_v1(const char *string, const char *spliter);

