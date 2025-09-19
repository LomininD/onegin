#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "string_funcs.h"


struct line_info
{
    char* line_ptr;
    size_t line_len;
};


line_info* split_poem(char* text_buf, size_t* text_ptr_size);
size_t get_line_num(char* text_buf);
line_info* initialise_text_ptr(size_t size);
line_info* get_text_ptr(size_t size, char* text_buf);


#endif
