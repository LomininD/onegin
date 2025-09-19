#ifndef INPUT_H
#define INPUT_H


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys/stat.h"

#include "string_funcs.h"


struct file_info
{
    FILE* fp;
    size_t file_size;
};


size_t get_file_size(file_info* file);
char* get_text_buf(file_info* file);


#endif
