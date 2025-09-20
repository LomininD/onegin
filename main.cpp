#include "main_headers.h"

//ask about pch

//TODO: get file name
//TODO: qsort
//TODO: read about struct offsets
//TODO: func pointers

//modes launch_mode = STANDARD;


void terminate_file_data(line_info* text_ptr, char* text_buf);
void print_lines(line_info* text_ptr, size_t size, FILE* stream);
void fill_output_file(line_info* text_ptr, size_t text_ptr_size, FILE* output);


int main()
{
    printf(MAKE_BOLD("ONEGIN LAUNCHED\n"));

    FILE* input = fopen("sample_onegin.txt", "r");
    FILE* output = fopen("output_file.txt", "w");

    file_info file = {input, 0};

    char* text_buf = get_text_buf(&file);

    size_t text_ptr_size = 0;
    line_info* text_ptr = split_poem(text_buf, &text_ptr_size);

    fill_output_file(text_ptr, text_ptr_size, output);

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


void fill_output_file(line_info* text_ptr, size_t text_ptr_size, FILE* output)
{
    assert(text_ptr != NULL);
    assert(output != NULL);

    fprintf(output, "ORIGINAL VERSION:\n\n");

    print_lines(text_ptr, text_ptr_size, output);

    bubble_sort(text_ptr, text_ptr_size, LTOR);

    fprintf(output, "LTOR SORTED VERSION:\n\n");

    print_lines(text_ptr, text_ptr_size, output);

    bubble_sort(text_ptr, text_ptr_size, RTOL);

    fprintf(output, "RTOL SORTED VERSION:\n\n");

    print_lines(text_ptr, text_ptr_size, output);
}


void print_lines(line_info* text_ptr, size_t size, FILE* stream)
{
    assert(text_ptr != NULL);

    for(size_t i = 0; i < size; i++)
    {
        char* line = (text_ptr + i)->line_ptr;
        size_t line_size = (text_ptr + i)->line_len;
        if (line_size > 1)
            my_fputs(line, stream);
    }

    fprintf(stream, "\n");
}
