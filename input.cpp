#include "input.h"

char* get_text_buf(file_info* file)
{
    FILE* file_ptr = file -> fp;

    assert(file_ptr != NULL);

    size_t file_size = file -> file_size = get_file_size(file);

    char* text_buf = (char*) calloc(file_size + 1, sizeof(*text_buf));

    assert(text_buf != NULL);

    printf("bytes in file: %zu\n", file_size); // if

    file_size = fread(text_buf, sizeof(char), file_size, file_ptr);
    *(text_buf + file_size + 1) = '\0';

    printf("bytes read: %zu\n", file_size); // if
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
