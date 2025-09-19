#include "main_headers.h"

//ask about pch

//TODO: get file name
//TODO: launch modes ?:
//TODO: qsort
//TODO: read about struct offsets
//TODO: func pointers

//modes launch_mode = STANDARD;


void terminate_file_data(line_info* text_ptr, char* text_buf);
void print_lines(line_info* text_ptr, size_t size, FILE* stream);


int main()
{
    printf(MAKE_BOLD("ONEGIN LAUNCHED\n"));

    FILE* input = fopen("sample_onegin.txt", "r");
    FILE* output = fopen("output_file.txt", "w");

    file_info file = {input, 0};

    char* text_buf = get_text_buf(&file);

    //puts(text_buf);

    size_t text_ptr_size = 0;
    line_info* text_ptr = split_poem(text_buf, &text_ptr_size);
    fputs(text_buf, output);
    //printf("line compare: %d\n\n", compare_lines(text_ptr + 1, text_ptr + 5));

    //swap_lines(text_ptr, text_ptr + 1);
    // my_puts(text_ptr->line_ptr);

    bubble_sort(text_ptr, text_ptr_size, LTOR);

    print_lines(text_ptr, text_ptr_size, output);

    bubble_sort(text_ptr, text_ptr_size, RTOL);

    print_lines(text_ptr, text_ptr_size, output);

    terminate_file_data(text_ptr, text_buf);

    fclose(input);
    fclose(output);

    return 0;
}


void terminate_file_data(line_info* text_ptr, char* text_buf)
{
    assert(text_ptr != NULL);
    assert(text_buf != NULL);

    free(text_ptr);
    free(text_buf);

    printf("termination succeeded\n");
}


void print_lines(line_info* text_ptr, size_t size, FILE* stream)
{
    assert(text_ptr != NULL);

    for(size_t i = 0; i < size; i++)
    {
        char* line = (text_ptr + i)->line_ptr;
        size_t line_size = (text_ptr + i)->line_len;
        if (line_size > 1)
            my_puts(line); //  TODO: ???
            my_fputs(line, stream);
    }

    printf("\n");
    fprintf(stream, "\n");
}
