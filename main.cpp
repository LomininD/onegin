#include "main_headers.h"

//ask about pch


//modes launch_mode = STANDARD;


void terminate_file_data(line_info* text_ptr, char* text_buf);


int main()
{
    printf(MAKE_BOLD("ONEGIN LAUNCHED\n"));

    FILE* fp = fopen("sample_onegin.txt", "r");
    file_info file = {fp, 0};

    char* text_buf = get_text_buf(&file);

    //puts(text_buf);

    size_t text_ptr_size = 0;
    line_info* text_ptr = split_poem(text_buf, &text_ptr_size);

    swap_lines(text_ptr, text_ptr + 1);

    my_puts(text_ptr->line_ptr);

    terminate_file_data(text_ptr, text_buf);
    fclose(fp);

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
