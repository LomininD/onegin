#include <stdio.h>
#include <assert.h>

#include "data_storage.h"


void bubble_sort(line_info* text_ptr, size_t ptr_arr_size);
int compare_lines(line_info* line_1, line_info* line_2);
int compare_symbols(char s1, char s2);
void swap_lines(line_info* line_1, line_info* line_2);

/*
void bubble_sort_int(int* arr, size_t size);
int compare_ints(int n1, int n2);
void swap_ints(int* n1, int* n2);
*/
