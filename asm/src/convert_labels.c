#include "../includes/asm.h"

void free_2d_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

char     *count_label_size(t_statement *state, int arg_i, int label_i, int check)
{
    int     start;
    int     end;
    int     count;
    int     result;
    char    *res;

    start = arg_i < label_i ? arg_i : label_i;
    end = arg_i > label_i ? arg_i : label_i;
    count = 0;
    result = 0;
    while (start > count)
    {
        state = state->next;
        count++;
    }
    while (end > count)
    {
        result = arg_i > label_i ? result - state->size : result + state->size;
        count++;
        state = state->next;
    }
    res = ft_itoa(result);
    if (check == 0)
        return (free_strjoin(ft_strdup("%"), res));
    return (res);
}

char    *count_label_index(char *str, t_statement *tmp, int check, int index)
{
    int         count;
    int         i;
    char        **arr;
    t_statement *state;

    count = 0;
    state = tmp;
    arr = ft_strsplit(str, ':');
    free(str);
    str = arr[0][0] == '%' ? ft_strdup(arr[1]) : ft_strdup(arr[0]);
    check = arr[0][0] == '%' ? 0 : 1;
    while (state)
    {
        i = 0;
        if (state->label)
            while (state->label[i])
            {
                if (ft_strcmp(str, state->label[i]) == 0)
                {
                    free_2d_array(arr);
                    return (count_label_size(tmp, index, count, check));
                }
                i++;
            }
        count++;
        state = state->next;
    }
    free_2d_array(arr);
    error_management("error while converting labels, no such label");
    return (NULL);
}

void    convert_labels(t_statement *tmp, int i, int count)
{
    t_statement *state;
    char        *temp;

    state = tmp;
    while (state)
    {
        i = -1;
        if (state->args)
            while (state->args[++i])
                    if (ft_strchr(state->args[i], ':'))
                    {
                        temp = count_label_index(state->args[i], tmp, 0, count);
                        free(state->args[i]);
                        state->args[i] = ft_strdup(temp);
                        free(temp);
                    }
        count++;
        state = state->next;
    }
}
