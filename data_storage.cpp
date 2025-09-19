#include "data_storage.h"


line_info* split_poem(char* text_buf, size_t* text_ptr_size)
{
    assert(text_buf != NULL);

    size_t line_num = get_line_num(text_buf); // refactor whole function
    *text_ptr_size = line_num + 1;

    printf("lines: %zu\n", line_num);
    printf("text_ptr size: %zu\n\n", *text_ptr_size); // if

    line_info* text_ptr = get_text_ptr(*text_ptr_size, text_buf);

    assert(text_ptr != NULL);

    return text_ptr;
}


size_t get_line_num(char* text_buf)
{
    assert(text_buf != NULL);

    size_t line_num = 0;

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

    for(size_t i = 1; i < size; i++) // ptr_arr consists of minimum 2 elements
    {
        size_t len = 0;

        while (*(text_buf + offset + len) != '\n')
        {
            len++;
        }

        (text_ptr + i)->line_ptr = text_buf + offset + len + 1;
        (text_ptr + i - 1)->line_len = len;

        offset += len + 1;
    }

    (text_ptr + size - 1)->line_len = 1;

    for(size_t i = 0; i < size; i++)
    {
        printf("line %zu, size %zu, ptr %p ", i + 1, (text_ptr + i)->line_len, (text_ptr + i)->line_ptr); // if
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
