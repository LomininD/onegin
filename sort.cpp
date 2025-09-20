#include "sort.h"


void bubble_sort(line_info* text_ptr, size_t ptr_arr_size, sort_modes mode)
{
    assert(text_ptr != NULL);

    //printf("started_sorting\n");

    int changed = 0;
    size_t to_change = ptr_arr_size;

    for (size_t i = 0; i < ptr_arr_size; i++)
    {
        for (size_t j = 0; j < to_change - 1; j++)
        {
            line_info* line_1 = text_ptr + j;
            line_info* line_2 = text_ptr + j + 1;

            if (!compare_lines(line_1, line_2, mode))
            {
                swap_lines(line_1, line_2);
                changed = 1;
            }
        }
        to_change--;

        if (!changed)
            break;
    }

}


// returns 1 if the order is correct
int compare_lines(line_info* line_1, line_info* line_2, sort_modes mode)
{
    assert(line_1 != NULL);
    assert(line_2 != NULL);

    size_t size_1 = line_1->line_len;
    size_t size_2 = line_2->line_len;

    char* str_1 = line_1->line_ptr;
    char* str_2 = line_2->line_ptr;

    int el_num_1 = 0, el_num_2 = 0;
    int str_1_shorter = el_num_1 == size_1;
    int next = 1;
    int is_comparable = el_num_1 < size_1 && el_num_2 < size_2;

    // printf("started comparing\n");
    // my_puts(str_1);
    // my_puts(str_2);
    // printf("\n");

    if (mode == RTOL)
    {
        el_num_1 = size_1 - 1, el_num_2 = size_2 - 1;
        str_1_shorter = el_num_1 == 0;
        next = -1;
        is_comparable = el_num_1 > 0 && el_num_2 > 0;
    }

    while (is_comparable)
    {
        //printf("comparing s1 = %c s1 = %c result = %d\n", *(str_1 + el_num_1), *(str_2 + el_num_2), compare_symbols(*(str_1 + el_num_1), *(str_2 + el_num_2)));

        switch (compare_symbols(*(str_1 + el_num_1), *(str_2 + el_num_2)))
        {
            case 1:
                return 1;
                break;

            case 0:
                return 0;
                break;

            case WRONG_S1:
                el_num_1 += next;
                break;

            case WRONG_S2:
                el_num_2 += next;
                break;

            default:
                el_num_1 += next;
                el_num_2 += next;
                break;
        }
    }

    if (str_1_shorter) // line 1 is shorter than line 2
        return 1;
    else
        return 0;
}


// returns 1 if the order is correct
int compare_symbols(char s1, char s2)
{
    if (!(isalpha(s1) || isalpha(s2)))
        return WRONG_ALL;

    else if (!isalpha(s1))
        return WRONG_S1;

    else if (!isalpha(s2))
        return WRONG_S2;

    else
    {
        char s1_norm = tolower(s1);
        char s2_norm = tolower(s2);
        if (s1_norm == s2_norm)
            return EQUAL;
        else
            return tolower(s1) < tolower(s2);
    }
}


void swap_lines(line_info* line_1, line_info* line_2)
{
    assert(line_1 != NULL);
    assert(line_2 != NULL);

    line_info buf = *line_1;
    *line_1 = *line_2;
    *line_2 = buf;
}


/*
void bubble_sort_int(int* arr, size_t size)
{
    assert(arr != NULL);

    int changed = 0;
    size_t to_change = size;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < to_change - 1; j++)
        {
            int* n1 = arr + j;
            int* n2 = arr + j + 1;

            if (compare_ints(*n1, *n2))
            {
                swap_ints(n1, n2);
                changed = 1;
            }
        }
        to_change--;

        if (!changed)
            break;
    }

}


int compare_ints(int n1, int n2)
{
    if (n1 > n2)
        return 1;
    else
        return 0;
}


void swap_ints(int* n1, int* n2)
{
    int buf = *n1;
    *n1 = *n2;
    *n2 = buf;
}
*/

