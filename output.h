#ifndef OUTPUT_H
#define OUTPUT_H


#include <stdio.h>
#include <assert.h>
#include "data_storage.h"
#include "string_funcs.h"


void print_lines(line_info* text_ptr, size_t size, FILE* stream);


#endif
