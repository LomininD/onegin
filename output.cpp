#include "output.h"


void print_lines(line_info* text_ptr, size_t size, FILE* stream)
{
    assert(text_ptr != NULL);

    for(size_t i = 0; i < size; i++)
    {
        char* line = (text_ptr + i)->line_ptr;
        size_t line_size = (text_ptr + i)->line_len;

        if (line_size > 1)
        {
            int written = fwrite(line, sizeof(char), line_size, stream);

            //my_fputs(line, stream);

            if (written != line_size)
            {
                printf("FAILED TO WRITE: \n");
                my_puts(line);
                printf("%d/%zu written\n", written, line_size);
            }

            fwrite("\n", sizeof(char), 1, stream);
        }
    }

    fwrite("\n\n", sizeof(char), 2, stream);
}
