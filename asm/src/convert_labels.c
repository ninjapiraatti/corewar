#include "../includes/asm.h"

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
        return (ft_strjoin("%", res));
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
    str = arr[0][0] == '%' ? arr[1] : arr[0];
    check = arr[0][0] == '%' ? 0 : 1;
    while (state)
    {
        i = 0;
        if (state->label)
            while (state->label[i])
            {
                if (ft_strcmp(str, state->label[i]) == 0)
                    return (count_label_size(tmp, index, count, check));
                i++;
            }
        count++;
        state = state->next;
    }
    return (NULL);
}

void    convert_labels(t_statement *tmp, int i, int count)
{
    t_statement *state;

    state = tmp;
    while (state)
    {
        i = -1;
        while (state->args[++i])
                if (ft_strchr(state->args[i], ':'))
                {
                    ft_printf("converting arg: %s, ", state->args[i]);
                    state->args[i] = count_label_index(state->args[i], tmp, 0, count);
                    ft_printf("converted to: %s\n", state->args[i]);
                }
        count++;
        state = state->next;
    }
}