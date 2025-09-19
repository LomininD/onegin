#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys/stat.h"


#include "font_styles.h"
#include "string_funcs.h"


struct file_info
{
    FILE* fp;
    size_t file_size;
};

struct line_info
{
    char* line_ptr;
    size_t line_len;
};


size_t get_file_size(file_info* file);
char* get_text_buf(file_info* file);
int get_line_num(char* text_buf);
line_info* initialise_text_ptr(size_t size);
line_info* get_text_ptr(size_t size, char* text_buf);
void terminate_file_data(line_info* text_ptr, char* text_buf);



int main()
{
    printf(MAKE_BOLD("ONEGIN LAUNCHED\n"));

    FILE* fp = fopen("sample_onegin.txt", "r");
    file_info file = {fp, 0};

    printf("sent file_ptr: %p\n", file.fp);

    char* text_buf = get_text_buf(&file);

    int line_num = get_line_num(text_buf);
    size_t text_ptr_size = line_num + 1;

    printf("lines: %d\n", line_num);
    printf("text_ptr size: %zu\n\n", text_ptr_size);

    //puts(text_buf);

    line_info* text_ptr = get_text_ptr(text_ptr_size, text_buf);

    terminate_file_data(text_ptr, text_buf);
    fclose(fp);

    return 0;
}


char* get_text_buf(file_info* file)
{
    FILE* file_ptr = file -> fp;

    assert(file_ptr != NULL);

    printf("received file_ptr: %p\n", file_ptr);

    size_t file_size = file -> file_size = get_file_size(file);

    char* text_buf = (char*) calloc(file_size + 1, sizeof(*text_buf)); // ask about sizeof

    assert(text_buf != NULL);

    printf("bytes in file: %zu\n", file_size);

    file_size = fread(text_buf, sizeof(char), file_size, file_ptr);
    *(text_buf + file_size + 1) = '\0';

    printf("bytes read: %zu\n", file_size);
    printf("reading done\n\n");

    return text_buf;
}


size_t get_file_size(file_info* file)
{
    FILE* fp = file -> fp;

    assert(fp != NULL);

    struct stat buf = {};
    fstat(fileno(fp), &buf);
    size_t sym_num = buf.st_size / sizeof(char);

    return sym_num;
}


int get_line_num(char* text_buf)
{
    assert(text_buf != NULL);

    int line_num = 0;

    while(*text_buf != '\0')
    {
        if (*text_buf == '\n' && *(text_buf + 1) != '\0')
            line_num++;

        text_buf++;
    }

    return line_num;
}


line_info* get_text_ptr(size_t size, char* text_buf)
{
    assert(text_buf != NULL);

    line_info* text_ptr = initialise_text_ptr(size);

    assert(text_ptr != NULL);

    printf("text_ptr initialised\n");
    printf("text_ptr address: %p\n\n", text_ptr);

    text_ptr->line_ptr = text_buf;

    size_t offset = 0;

    for(int i = 1; i < size; i++)
    {
        size_t len = 0;

        while (*(text_buf + offset + len) != '\n')
        {
            len++;
        }

        len++;

        (text_ptr + i)->line_ptr = text_buf + offset + len;
        (text_ptr + i - 1)->line_len = len;

        offset += len;
    }

    (text_ptr + size - 1)->line_len = 1;

    for(int i = 0; i < size; i++)
    {
        printf("line %d, size %zu, ptr %p ", i + 1, (text_ptr + i)->line_len, (text_ptr + i)->line_ptr);
        my_puts((text_ptr + i)->line_ptr);
    }

    printf("\ntext_ptr ready\n\n");

    return text_ptr;
}


line_info* initialise_text_ptr(size_t size)
{
    line_info* text_ptr = (line_info*) calloc(size, sizeof(*text_ptr));

    assert(text_ptr != NULL);

    return text_ptr;
}


void terminate_file_data(line_info* text_ptr, char* text_buf)
{
    assert(text_ptr != NULL);
    assert(text_buf != NULL);

    free(text_ptr);
    free(text_buf);

    printf("termination succeeded\n");
}


