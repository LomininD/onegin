#include "sort.h"
// структурные переменные присваиваются друг другу автоматически


// void bubble_sort(line_info* text_ptr, size_t ptr_arr_size)
// {
//     assert(text_ptr != NULL);
//
//     int changed = 0;
//     size_t to_change = ptr_arr_size;
//
//     for (size_t i = 0; i < ptr_arr_size; i++)
//     {
//         for (size_t j = 0; j < to_change - 1; j++)
//         {
//             line_info* line_1 = text_ptr + j;
//             line_info* line_2 = text_ptr + j + 1;
//
//             if (compare_lines(line_1, line_2))
//             {
//                 swap_lines(line_1, line_2);
//                 changed = 1;
//             }
//         }
//         to_change--;
//
//         if (!changed)
//             break;
//     }
//
// }


void swap_lines(line_info* line_1, line_info* line_2)
{
    line_info* buf = line_1;
    line_1 = line_2;
    line_2 = buf;
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

