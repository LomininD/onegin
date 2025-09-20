#include "main_headers.h"

//ask about pch
//TODO: qsort
//TODO: func pointers


void terminate_file_data(line_info* text_ptr, char* text_buf);
void fill_output_file(line_info* text_ptr, size_t text_ptr_size, FILE* output);


int main(int argc, const char* argv[])
{
    printf(MAKE_BOLD("ONEGIN LAUNCHED\n"));

    FILE* input = NULL;

    if(argc == 2)
        input = fopen(argv[1], "r");
    else
        input = fopen("sample_onegin.txt", "r");

    FILE* output = fopen("output_file.txt", "w");

    assert(input != NULL);
    assert(output != NULL);

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


void terminate_file_data(line_info* text_ptr, char* text_buf)
{
    assert(text_ptr != NULL);
    assert(text_buf != NULL);

    free(text_ptr);
    free(text_buf);

    printf("termination succeeded\n");
}
